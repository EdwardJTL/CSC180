//
//  main.c
//  Lab5
//
//  Created by Edward Luo on 2017-10-16.
//  Copyright © 2017 Edward Luo. All rights reserved.
//

#include <stdio.h>

int squareInt(int x);

int main(void) {
    int i;
    for(i=0;i<10;i++){
        int sq=squareInt(i);
        printf("Hello world; %d squared is %d\n",i,sq);
        if (sq%2!=0){
            printf("The square is odd!\n");
        }
    }
    return 0;
}

int squareInt(int x){
    return x*x;
}
