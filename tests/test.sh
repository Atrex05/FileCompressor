#!/bin/bash

make > /dev/null

mkdir temp temp/compressed temp/uncompressed

get_type() {
    if [[ "$1" == *.lyr ]]; then
        echo 1
    elif [[ "$1" == *.html ]]; then
        echo 2
    elif [[ "$1" == *.ppm ]]; then
        echo 3
    fi
}

for i in `ls ./tests/test_files/*`; do
    file=${i##\.\/tests\/test_files\/}

    echo "Testing: $file"

    (time ./antman/antman $i $(get_type $i) > ./temp/compressed/$file.compressed) \
        2>&1 | grep real | awk '{ print "time: " substr($2, 3, 6) }'

    (valgrind --leak-check=full ./antman/antman $i $(get_type $i) > ./temp/compressed/$file.compressed) \
        2>&1 | grep "ERROR SUMMARY" | awk '{ $1=""; print "valgrind: " $0 }'

    ls -lh $i | awk '{ print "original: " $5 }'
    ls -lh ./temp/compressed/$file.compressed | awk '{ print "compressed: " $5 }'

    ./giantman/giantman ./temp/compressed/$file.compressed $(get_type $i) > \
        ./temp/uncompressed/$file.uncompressed

    if [[ "$(diff ./temp/uncompressed/$file.uncompressed $i)" != "" ]]; then
        echo "ERROR: uncompressed output does not match source !"
        exit 1
    else
        echo "SUCCESS for $i"
    fi

    echo ""
    echo ""

done

rm -rf temp
