add_subdirectory("Project 2")
add_executable (Lab1_1 lab1_1.c)
add_executable (Lab1_2 lab1_2.c)
add_executable (Lab2 lab2.c)
add_executable (Lab3 lab3.c lab3_ll.c)
add_executable (Lab4 lab4.c lab3_ll.c)
add_executable (Project1 "Project 1/main.c" "Project 1/autocomplete.c")
# add_executable (Project1_tester  "src/Project 1/project1_tester/tester.c" "src/Project 1/project1_tester/autocomplete.c")
add_executable (Lab7 "lab7.c" "Project 2/c_img.c")
add_subdirectory(lab8)

# cmake .. -G"MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=MAKE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang