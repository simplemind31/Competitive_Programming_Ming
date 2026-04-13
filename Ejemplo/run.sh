g++ A.cpp -o A
for x in {1..4};do
    echo "file $x"
    ./A < examples/$x.in
    echo "----------"
done
    