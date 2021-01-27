cmake_minimum_required (VERSION 3.8)
project ("ESC190-lab-2")
add_executable (lab2 "src/lab2.c")

# cmake .. -G"MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=MAKE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang