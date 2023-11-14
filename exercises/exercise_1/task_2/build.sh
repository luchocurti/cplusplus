#!/bin/bash

echo Compile and assemble \"subtract\"
g++ -std=c++14 -Wall -O0 -c ./src/subtract.cpp -I ./include/ -o ./results/lib/subtract.o
sleep 0.5
echo "   Output = ./results/lib/subtract.o"
echo " "

echo Compile and assemble \"sum\"
g++ -std=c++14 -Wall -O0 -c ./src/sum.cpp -I ./include/ -o ./results/lib/sum.o
sleep 0.5
echo "   Output = ./results/lib/sum.o"
echo " "

echo Make an archive of the objects to create the static library
ar rcs ./results/lib/libipb_arithmetic.a ./results/lib/sum.o ./results/lib/subtract.o > /dev/null 2>&1
sleep 0.5
echo "   Output = ./results/lib/libipb_arithmetic.a"
echo " "

echo Compile and assemble \"main\"
g++ -std=c++14 -Wall -O0 -c ./src/main.cpp -I ./include/ -o ./results/bin/main.o
sleep 0.5
echo "   Output = ./results/bin/main.o"
echo " "

echo Link \"main\" with \"ipb_arithmetic\" library
# Many separated object files option:
# g++ -std=c++14 -Wall -O0 ./results/lib/*.o ./results/bin/main.o -o ./results/bin/main.out
# One library file option:
g++ -std=c++14 -Wall -O0 ./results/bin/main.o -L./results/lib/ -lipb_arithmetic -o ./results/bin/main.out
sleep 0.5
echo "   Output = ./results/bin/main.out"
echo " "
