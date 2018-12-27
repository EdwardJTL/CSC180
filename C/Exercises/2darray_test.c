#include<stdio.h>
#include<stdlib.h>

int main(void){
    int matrix[3][3];
    int i;
    for (i=0;i<3;i++){
        matrix[i][i] = i;
    }
    printf("%d",matrix[3][3]);
}
