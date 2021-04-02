cmake_minimum_required (VERSION 3.8)
project ("ESC190-labs" C)
add_subdirectory("src")

# cmake .. -G"MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=MAKE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang