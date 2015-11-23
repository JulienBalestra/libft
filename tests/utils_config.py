import os
from subprocess import call
import subprocess as subp
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


def valgrind_wrapper(program, leaks=False, errors=False, debug=False, args=None):
	"""
	Wrapper of valgrind
	"""
	valgrind = "/usr/bin/valgrind"
	assert os.path.isfile(valgrind) is True
	if leaks is True:
		vg_cmd = [valgrind, "--tool=memcheck", "--leak-check=full"]
	elif errors is True:
		vg_cmd = [valgrind, "--track-origins=yes"]
	else:
		raise RuntimeError("Choose leaks or errors mode")
	try:
		ret = subp.check_output(vg_cmd + [program] + [arg for arg in list(args)], stderr=subp.STDOUT)
	except TypeError:
		ret = subp.check_output(vg_cmd + [program], stderr=subp.STDOUT)
	if debug is True:
		print ret
	if leaks is True:
		summary = [leak.split("==    ")[1] for leak in ret.split("\n") if "lost:" in leak]
		if len(summary) > 0:
			return summary
	elif errors is True:
		summary = ret.split("\n")[-2].split("== ")[1]
		if "ERROR SUMMARY: 0 errors from 0 contexts" not in summary:
			return summary
	return False
