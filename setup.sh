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
    return $?
}

main
exit $?
