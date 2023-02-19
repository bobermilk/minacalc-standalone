# minacalc-standalone
Standalone version of MinaCalc along with a C API for easy access and bindings by my ET fren kangalio

# How to compile
`
clang++ -std=c++17 -O2 -c MinaCalc/MinaCalc.cpp API.cpp smloader.cpp
llvm-ar rcs libminacalc.a *.o
clang  main.c libminacalc.a
`
