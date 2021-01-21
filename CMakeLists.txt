cmake_minimum_required (VERSION 3.8)
project ("ESC190-lab-1")
add_executable (lab1-2 "src/lab1-2.c")

# cmake .. -G"MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=MAKE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang