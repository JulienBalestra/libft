#!/bin/bash

function go_to_dirname
{
    echo "Go to working directory..."
    cd $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
    if [ $? -ne 0 ]
    then
        echo "go_to_dirname failed";
        exit 1
    fi
    echo "-> Current directory is" $(pwd)
}

function config_moulitest
{
    mv tests/moulitest/config.ini tests/moulitest/config.ini.old 2> /dev/null
    while read line
    do
        # ${path} in main scope
        output=${line/"@path"/${path}/}
        echo ${output} >> tests/moulitest/config.ini
    done < tests/moulitest.config

}

function packages
{
    valgrind --version
    if [ $? -eq 0 ]
    then
        echo "valgrind already setup"
        return 0
    fi
    echo "Updating package source..."
    sudo apt-get update -qq || sudo brew update > /dev/null
    for package in valgrind
    do
        echo "Installing package named ${package}"
        sudo apt-get install ${package} -y > /dev/null || sudo brew install ${package} > /dev/null
        which ${package}
    done
}

function setup_submodules
{
    printf "\nSetup git submodules...\n"
    for module in tests/moulitest
    do
        git submodule init ${module}
        git submodule update --remote ${module} || git submodule update ${module}
    done
    printf "\n-> Git submodules set\n"
}

function main
{
    # Requirements
    go_to_dirname
    path=$(pwd)
    setup_submodules
    config_moulitest
    packages
    return $?
}

main
exit $?
