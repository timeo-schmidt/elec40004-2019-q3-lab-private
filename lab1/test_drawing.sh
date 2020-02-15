g++ house.cpp -o house && g++ spiral.cpp -o spiral && ./house > house.got.svg && ./spiral > spiral.got.svg

if [[ $? != 0 ]]; then
        echo "Compilation Failed with error code: " $?
        exit 1
fi

if ! cmp house.got.svg house.ref.svg >/dev/null 2>&1
then
    echo "House different."
    exit 1
fi

if ! cmp spiral.got.svg spiral.ref.svg >/dev/null 2>&1
then
    echo "Spiral different."
    exit 1
fi

echo "Success"
exit 0
