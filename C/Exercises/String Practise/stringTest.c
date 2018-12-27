//
//  stringTest.c
//  
//
//  Created by Edward Luo on 2017-11-27.
//

#include <stdio.h>

int printNlength(char* inarray);
char *strConcat1(char* a1, char* a2);

int printNlength(char* inarray){
    int length;
    printf("%s\n", inarray);
    for (length=0;inarray[length]!='\0';length++);
    return length;
}

char *strConcat1(char* a1, char* a2){
    int length1;
    int length2;
    for (length1=0;a1[length1]!='\0';length1++);
    for (length2=0;a2[length2]!='\0';length2++){
        a1[length1+length2] = a2[length2];
    }
    return a1;
}

int main(void){
    char a1[255]="End-of-term";
    char a2[255]="IS COMING";
    printf("Length of a1 is %d\n",printNlength(a1));
    printf("%s\n",strConcat1(a1,a2));
    return 1;
}

