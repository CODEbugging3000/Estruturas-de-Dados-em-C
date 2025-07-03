#include <stdio.h>
#include <stdlib.h>

/* The QuickSort function implements the Quick Sort algorithm to sort an array of integers in place. 
It recursively partitions the array around a pivot element and sorts the subarrays on either side of the pivot.*/
int QuickSort(int *v, int left, int right) {
    if (left < right) {
        int pivot = v[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (v[j] <= pivot) {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        int temp = v[i + 1];
        v[i + 1] = v[right];
        v[right] = temp;
        int partitionIndex = i + 1;
        QuickSort(v, left, partitionIndex - 1);
        QuickSort(v, partitionIndex + 1, right);
    }
    return 0;
}


int main(){
    int v[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(v) / sizeof(v[0]);
    QuickSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
// This code implements the Quick Sort algorithm in C, which sorts an array of integers in ascending order.