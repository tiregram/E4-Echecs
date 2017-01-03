# !/bin/sh

for i in *.cpp;
do
    g++ -ansi -pedantic -Wall -Wextra -std=c++1y $i -c -g
done

g++ *.o
