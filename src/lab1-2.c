#if 0
Lab 1
=====

2. Implement a function that performs Insertion Sort https://en.wikipedia.org/wiki/Insertion_sort#Algorithm
   The function should take in an array of integers, and modify the array so that it's 
   sorted in increasing order.
  
   Here is code to print out an array of integers using a for-loop and a while-loop in C.

   int i = 0;
   int a[5] = {2, 3, 4, 5, 6};
   // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
   // Here, i++ is the same as i = i + 1
   for(i = 0; i < 5; i++){
       printf("%d\n", a[i]);
   }

   i = 0;
   while(i < 5){
       printf("%d\n", a[i]);
       i++; // same as i = i + 1
   }
#endif

#include <stdio.h>

void print_array(int length, int* arr)
{
    int i = 0;
    for(i = 0; i < length; i++){
        printf("%d  ", arr[i]);
    }
}

void insertion_sort(int length, int* arr)
{
    int i = 1, j, current_num;
    for(; i < length ; i++)
    {
        current_num = arr[i];
        for(j = i - 1; arr[j] > current_num && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current_num;
    }
}

int main()
{
#define ARRAY_LEN 26
    int arr[ARRAY_LEN] = {8,7,7,45,5,5,8,74,54,5,78,7,7,4,5,58,58,7,4,15,5,7,74,14,5,8};
    print_array(ARRAY_LEN, arr);
    insertion_sort(ARRAY_LEN, arr);
    printf("\n\n");
    print_array(ARRAY_LEN, arr);
}