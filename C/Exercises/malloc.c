#include<stdio.h>
#include<stdlib.h>

int computeAverage(int *data, int size, float *average);

int main(void){
    int n = 0;
    int i = 0;
    int *dynArray = NULL;
    int staticArray[10];
    int status = 0;
    float avg = 0;

    status = computeAverage(dynArray, n, &avg);
    if (status == -1){
        printf("ERR: computeAverage failed\n");
    } else{
        printf("INFO: average is %f\n", avg);
    }

    printf("How many numbers do you want to process?\n");
    scanf("%d", &n);
    dynArray = (int*)malloc(n*sizeof(int));

    for (i=0;i<n;i=i+1){
        int tmp = 0;
        printf("Enter a number: ");
        scanf("%d",&tmp);
        dynArray[i] = tmp;
    }

    status = computeAverage(dynArray,n,&avg);
    if (status == -1){
        printf("ERR:computeAverage failed\n");
    } else {
        printf("INFO: average is %f\n", avg);
    }

    free(dynArray);
    return 0;
}

int computeAverage(int *data, int size, float *average){
    int i = 0;
    float r =0;
    if ((data == NULL)||(average==NULL)){
        printf("ERR: computeAverage called with a NULL pointer\n");
        return -1;
    }
    for (i=0;i<size;i++){
        r=r+data[i];
    }
    (*average) = r/((float)size);
    return 0;
}
