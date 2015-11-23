import os
from subprocess import call
from multiprocessing import Process, cpu_count
import subprocess
from unittest import TestLoader


class IterMethods():
	def __init__(self, test_case_class):
		my_load = TestLoader()
		self.methods = my_load.getTestCaseNames(test_case_class)

	def __iter__(self):
		for method in self.methods:
			yield method


class SetLibftConfig:
	def __init__(self, debug_mod):
		self.debug_mod = debug_mod
		self.files = None

	def next_conf(self, test_method_name):
		ft_filename = "ft" + test_method_name[4:]
		lib_dir = "%s/" % os.path.split(os.path.dirname(__file__))[0]
		self.files = {"bin": lib_dir + ft_filename + ".bft",
					  "src_ft": lib_dir + "/srcs/" + ft_filename + ".c",
					  "main_ft_filename": os.path.dirname(
						  os.path.abspath(__file__)) + "/libft_mains/main_" + ft_filename + ".c",
					  "lib_ft": lib_dir + "libft.a",
					  "lib_dir": lib_dir,
					  "includes": lib_dir + "includes/"}
		return self.start_compilation()

	def is_files(self):
		return os.path.isfile(self.files["lib_ft"]) == os.path.isfile(self.files["main_ft_filename"]) == \
			   os.path.isdir(self.files["includes"])

	def is_clean(self):
		forbidden = ["stdio.h", "printf"]
		with open(self.files["src_ft"], 'r') as ft_file:
			for line in ft_file.readlines():
				for error in forbidden:
					if error in line:
						return False
		return True

	def start_compilation(self):
		assert self.is_files() is True
		if os.path.isfile(self.files["bin"]) is True:
			os.remove(self.files["bin"])
		if self.debug_mod is False:
			assert self.is_clean() is True
		cmd = ["gcc", "-Werror", "-Wextra", "-Wall", self.files["main_ft_filename"], self.files["lib_ft"], "-I",
			   self.files["includes"], "-o", self.files["bin"]]
		assert call(cmd) == 0
		return self.files["bin"]


def valgrind_wrapper(program, full_leaks=False):
	valgrind = ["valgrind"]
	if full_leaks is True:
		valgrind = ["valgrind", "--leak-check=full"]

	print program
	program = valgrind + program
	p_command = subprocess.Popen(program, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	stdout, stderr = p_command.communicate()

	summary = [leak.split("==    ")[1] for leak in stderr.split("\n") if "lost:" in leak]
	if len(summary) > 0 and "definitely lost: 0 bytes in 0 blocks" not in summary:
		if full_leaks is False:
			valgrind_wrapper(program, True)
			return False
		os.write(2, "\n\n%s\n" % str(program))
		os.write(2, "%s\n" % stderr)
		raise AssertionError("%s" % summary)

	summary = stderr.split("\n")[-2].split("== ")[1]
	if "ERROR SUMMARY: 0 errors from 0 contexts" not in summary:
		os.write(2, "\n\n%s\n" % str(program))
		os.write(2, "%s\n" % stderr)
		raise AssertionError("%s" % summary)
	return False


class QueueProcess:
	p = []
	cores = cpu_count() + 1
	join_number = (cores / 2) + 1

	def __init__(self, function, tail, *args):
		self.args = args
		self.function = function
		self.tail = tail
		self.process = Process(target=self.function, args=self.args)

	def start(self):
		self.manage_queue()
		self.process.start()
		if self.tail is True:
			self.process.join()
			if self.process.exitcode != 0:
				raise AssertionError
		self.p.append(self)

	def manage_queue(self):
		state = [p for p in self.p if p.process.is_alive()]
		if len(state) > self.cores:
			for i in range(0, self.join_number):
				state[i].process.join()
