/**
 * Name: Siddharth Kakked
 * Date: 2024-09-15
 * Semester: Fall 2025
 */
#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int minIndex = start; // assume the first is the min
    for (int i = start + 1; i < stop; i++) // look at each other element
    {
        if (array[i] < array[minIndex]) // find a new minimum
        {
            minIndex = i; // remember where it is
        }
    }
    return minIndex; // modify to return the index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    for (unsigned int i = 0; i < size - 1; i++) // for each position in the array
    {
        int minIndex = findMinimum(array, i, size); // find the index of the minimum value
        if (minIndex != i) // if it's not already in the right place
        {
            swap(&array[i], &array[minIndex]); // swap it into place
        }
        if (print) // if print is true (non-zero)
        {
            printIntArray(array, size); // print the array after each iteration
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    for (unsigned int i = 1; i < size; i++) // for each element in the array, starting at index 1
    {
        int key = array[i]; // the value to be inserted into the sorted portion
        int j = i - 1;     // the last index of the sorted portion

        // Move elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j]; // shift element to the right
            j--;                     // move to the previous element
        }
        array[j + 1] = key; // insert the key at its correct position

        if (print) // if print is true (non-zero)
        {
            printIntArray(array, size); // print the array after each iteration
        }
    }

}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    for (unsigned int i = 0; i < size - 1; i++) // for each position in the array
    {
        int swapped = 0; // flag to check if any swapping occurred
        for (unsigned int j = 0; j < size - i - 1; j++) // last i elements are already sorted
        {
            if (array[j] > array[j + 1]) // if the current element is greater than the next
            {
                swap(&array[j], &array[j + 1]); // swap them
                swapped = 1; // set the flag to indicate a swap occurred
            }
        }
        if (print) // if print is true (non-zero)
        {
            printIntArray(array, size); // print the array after each iteration
        }
        if (swapped == 0) // if no two elements were swapped in the inner loop, then break
        {
            break;
        }
    }
}


// ** You will work on merge sort during the lab on Module 06 ** //
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }
    if (l > m || m + 1 > r)
        return;

    // Copy data to temp array
    for (int i = l; i <= r; i++)
    {
        temp[i] = arr[i];
    }

    int i = l;       // Initial index of first subarray
    int j = m + 1;   // Initial index of second subarray
    int k = l;       // Initial index of merged subarray

    // Merge the temp arrays back into arr[l..r]
    while (i <= m && j <= r)
    {
        if (temp[i] <= temp[j])
        {
            arr[k] = temp[i];
            i++;
        }
        else
        {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray, if any
    while (i <= m)
    {
        arr[k] = temp[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray, if any
    while (j <= r)
    {
        arr[k] = temp[j];
        j++;
        k++;
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // Find the middle point
        
        merge_sort(arr, temp, l, m);     // Sort first half
        merge_sort(arr, temp, m + 1, r); // Sort second half
        merge(arr, temp, l, m, r);       // Merge the sorted halves
    }
}

// lab build, merge sort
void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;
    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif