#include<stdio.h>
#include<stdlib.h>

int main(void){
    int l1[3]={1,2,3};
    printf("The result of l1[0] is %d.\n", l1[0]);
    printf("The result of *l1 is %d.\n", *l1);
    int r;
    scanf("Print a number: %d", &r);
    printf("Here you go: %d.\n", r);
    return 0;
}
