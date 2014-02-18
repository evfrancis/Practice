#include "algorithms.h"
#include "string.h"

// Run binary search on an array from range lo to hi for val
int binarySearch(int* array, int lo, int hi, int val) {
    while (lo <= hi) {
        int median = (lo+hi)/2;
        if (val < array[median]) {
            hi = median-1;
        } else if (val > array[median]) {
            lo = median+1;
        } else {
            return median;
        }
    }
    return -1;
}

void quickSort(int* array, int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = array[left];
    while (left < right)
    {
        while ((array[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            array[left] = array[right];
            left++;
        }
        while ((array[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(array, left, pivot-1);
    if (right > pivot)
        quickSort(array, pivot+1, right);
}


