#include <stdio.h>

int bubbleSort(int *array, int size);

int bubbleSort(int *array, int size){
    if (size<1) {
        return -1;
    }
    if (array == NULL) {
        return -1;
    }
    int n = size;
    int swapping = 0;
    while (swapping == 0){
        int swapped = 0;
        int i;
        for (i=1;i<n;i+=1){
            if (array[i-1]>array[i]) {
                int temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
                swapped = 1;
            }
        }
        n = n-1;
        if (swapped == 0){
            swapping = 1;
        }
    }
    return 0;
}
