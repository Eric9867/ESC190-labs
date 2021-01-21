#if 0
Lab 1
=====

1. In your main function, define the variable int a and initialize it to 5.
   Now, write a function which does not return anything, but can set the value of 
   an integer to 10.
   
   Use this function to set the value of a to 10.
   
   Use printf to demonstrate that the value of a changed.
   
   Now, put a breakpoint at int a = 5, and trace the code.

#endif

#include <stdio.h>

void set_int_to_10(int* num)
{
    *num = 10;
}

int main()
{
    int a = 5;
    printf("%d\n", a);
    set_int_to_10(&a);
    printf("%d\n", a);
}