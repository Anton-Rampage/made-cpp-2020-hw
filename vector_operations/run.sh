#!/bin/bash

set -e

g++ -std=c++17 -I./src test/test.cpp -o vector_ops_test -fconcepts
./vector_ops_test

echo All tests passed!