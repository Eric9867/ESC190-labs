cmake_minimum_required (VERSION 3.8)
project ("ESC190-labs" C)
add_subdirectory("src/Project 2")
add_executable (Lab1_1 src/lab1_1.c)
add_executable (Lab1_2 src/lab1_2.c)
add_executable (Lab2 src/lab2.c)
add_executable (Lab3 src/lab3.c src/lab3_ll.c)
add_executable (Lab4 src/lab4.c src/lab3_ll.c)
add_executable (Project1 "src/Project 1/main.c" "src/Project 1/autocomplete.c")
# add_executable (Project1_tester  "src/Project 1/project1_tester/tester.c" "src/Project 1/project1_tester/autocomplete.c")

add_executable (Lab7 "src/lab7.c" "src/Project 2/c_img.c")


# cmake .. -G"MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=MAKE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang