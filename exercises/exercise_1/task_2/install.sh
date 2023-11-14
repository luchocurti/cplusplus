#!/usr/bin/bash

# ├── install
# │   ├── include
# │   │   ├── ipb_arithmetic
# │   │   │   ├── subtract.hpp
# │   │   │   └── sum.hpp
# │   │   └── ipb_arithmetic.hpp
# │   └── lib
# │       └── libipb_arithmetic.a

echo Create \"include\" folder
mkdir -p ./install/include
sleep 0.5
echo "   Output = ./install/include/"
echo " "

echo Create \"ipb_arithmetic\" folder
mkdir -p ./install/include/ipb_arithmetic
sleep 0.5
echo "   Output = ./install/include/ipb_arithmetic/"
echo " "

echo Create \"lib\" folder
mkdir -p ./install/lib
sleep 0.5
echo "   Output = ./install/lib/"
echo " "

echo Move *.hpp files to ./install/include/ folder
cp ./include/ipb_arithmetic/*.hpp ./install/include/ipb_arithmetic/
cp ./include/*.hpp ./install/include/
sleep 0.5
echo "   Output = ./install/include/*.hpp"
echo " "

echo Move the library to ./install/lib/
cp ./results/lib/*.a ./install/lib
sleep 0.5
echo "   Output = ./install/lib/*.a"
echo " "
