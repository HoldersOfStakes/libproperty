#!/bin/bash

find ../src ../include -name "*.h" -o -name "*.cpp" -print | xargs -I{} clang-tidy -p=./ {} -- -I`pwd`/../include -std=c++14 > tidy_output.txt

if [[ -n $(grep "warning: " tidy_output.txt) ]] || [[ -n $(grep "error: " tidy_output.txt) ]]; then
    grep --color -E '^|warning: |error: ' tidy_output.txt
    exit -1;
else
    echo -e "\033[1;32m\xE2\x9C\x93 passed\033[0m";
fi
