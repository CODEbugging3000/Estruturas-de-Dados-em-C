#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int *v, int size){
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return 0;
}


int main(){
    int v[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(v) / sizeof(v[0]);
    BubbleSort(v, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}