#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -fpic -c *.c
gcc -shared -o liball.so *.o