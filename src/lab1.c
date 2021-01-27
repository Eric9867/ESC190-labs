#include <stdio.h>
#define SIZE 10
/* 
Lab 1
=====

1. In your main function, define the variable int a and initialize it to 5.
   Now, write a function which does not return anything, but can set the value of 
   an integer to 10.
   
   Use this function to set the value of a to 10.
   
   Use printf to demonstrate that the value of a changed.
   
   Now, put a breakpoint at int a = 5, and trace the code.

2. Implement a function that performs Insertion Sort https://en.wikipedia.org/wiki/Insertion_sort#Algorithm
   The function should take in an array of integers, and modify the array so that it's 
   sorted in increasing order.
  
   Here is code to print out an array of integers using a for-loop and a while-loop in C.
*/

// 1
void int_to_10(int *p_int){
    *p_int = 10;
}

// 2
void insertion_sort(int *a, int A_SIZE){
    //start at index 0 ++
    //at index i, if next index is smaller, starting at j = i, count down till no longer true and swap each element
    int j;
    int temp;
    for(int i = 1; i < A_SIZE; i++){
        j = i;
        while(j-1 >= 0 && a[j-1] > a[j]){
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
}

void print_arrf(int *a, int A_SIZE){
    printf("[");
    for(int i = 0; i < A_SIZE; i++){
        printf("%d", a[i]);
        if (i != A_SIZE - 1){
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void){
    //PART 1
    int a = 5;
    int *p_a = &a;
    int_to_10(p_a);
    printf("%ld\n",a);

    //PART 2
    int arr[SIZE] = {6, 5, 3, 1, 2, 4, 4, 2, 152, 12};
    
    print_arrf(arr, SIZE);

    insertion_sort(arr, SIZE);

    print_arrf(arr, SIZE);
}




// void insertion_sort(int *a, int A_SIZE){
//     //start at index 0 ++
//     //at index i, if next index is smaller, starting at j = i, count down till no longer true and swap each element
//     int j;
//     int temp;
//     for(int i = 1; i < A_SIZE; i++){
//         j = i;
//         while(j-1 >= 0 && a[j-1] > a[j]){
//             //swap(&a[j], &a[j-1]);
//             temp = *(a + j);
//             *(a + j) = *(a + j-1);
//             *(a + j-1) = temp;
//             j--;
//         }
//     }
// }

