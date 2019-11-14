#!/bin/bash
# $1 名字
# $2 可执行文件名
# =================================================
#                Config
# =================================================
one=100
two=370
three=753
four=1076
five=1428
start=50
end=5000
# =================================================
if [ "$1" = "-c" ]; then
    g++ -o generate generate.cpp

    if [ ! -d "test_case" ]; then
        mkdir test_case
        cd test_case
        for ((i = 10; i <= 150; i = i + 20)); do
            ../generate $i >$i
        done
        # ../generate $one > $one
        # ../generate $two > $two
        # ../generate $three > $three
        # ../generate $four > $four
        # ../generate $five > $five

        cd ../
    fi

    # Answer
    cd users/$2
    rm *ans
    for file in $(ls ../../test_case); do
        echo "Unsorted ${file}"
        ./$3 -i UNSORTED -v <"../../test_case/${file}" >"${file}_unsorted_ans"
        echo "Fib ${file}"
        ./$3 -i FIBONACCI -v <"../../test_case/${file}" >"${file}_fib_ans"
        echo "Binary ${file}"
        ./$3 -i BINARY -v <"../../test_case/${file}" >"${file}_binary_ans1"
        ./$3 --implementation BINARY -v <"../../test_case/${file}" >"${file}_binary_ans2"
        ./$3 -i BINARY --verbose <"../../test_case/${file}" >"${file}_binary_ans3"
        ./$3 -i BINARY <"../../test_case/${file}" >"${file}_binary_ans4"
        ./$3 --implementation BINARY <"../../test_case/${file}" >"${file}_binary_ans5"

    done
    cd ../../
fi
if [ "$1" = "-t" ]; then
    g++ -o generate generate.cpp
    # Time
    cd users/$2
    if [ -d "time" ]; then
        rm -r time
    fi
    mkdir time
    rm *.csv
    rm fib.csv
    touch unsorted.csv
    touch fib.csv
    touch binary.csv
    for ((i = 0; i < 5; i = i + 1)); do
        echo "The ${i}th test"
        cd time
        for ((j = $start; j < $end; j = j + 495)); do
            ../generate $j >$j
        done
        cd ../
        for file in $(ls time); do
            echo "Unsorted ${file}"
            ./$3 -i UNSORTED <"time/${file}" >>"unsorted.csv"
            echo "Fib ${file}"
            ./$3 -i FIBONACCI <"time/${file}" >>"fib.csv"
            echo "Binary ${file}"
            ./$3 -i BINARY <"time/${file}" >>"binary.csv"
        done
    done

    cd ../../
fi

if [ "$1" = "-d" ]; then
    if [ -d "diff_result" ]; then
        rm -r diff_result
    fi
    mkdir diff_result
    cd diff_result
    for file in $(ls ../users/$2); do
        diff ../users/$2/${file} ../users/$3/${file} >${file}_diff
    done
    cd ../
    ls -al diff_result
fi
