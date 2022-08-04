#!/bin/bash

for f in tests/*/*/*.i; do
    pre=${f%.i}
    expected=$pre.ex
    out=$pre.o
    echo "Cheking $f ..."
    make lexer < $f > $out
    if diff -q $out $expected
    then
        echo "$(tput setaf 2)Success $(tput setaf 7)"
    else
        echo "$(tput setaf 1)Failure $(tput setaf 7)"
    fi
done