//
//  fibo.c
//  
//
//  Created by Edward Luo on 2017-11-15.
//

#include <stdio.h>

int fibo(int n);

int main(void){
    printf("%d\n",fibo(0));
    printf("%d\n",fibo(1));
    printf("%d\n",fibo(2));
    printf("%d\n",fibo(3));
    printf("%d\n",fibo(4));
    printf("%d\n",fibo(5));
    printf("%d\n",fibo(6));
    printf("%d\n",fibo(7));
    printf("%d\n",fibo(8));
    printf("%d\n",fibo(9));
    printf("%d\n",fibo(10));
    printf("%d\n",fibo(11));
    printf("%d\n",fibo(12));
    printf("%d\n",fibo(13));
    return 1;
}

int fibo(int n){
    if (n==0) {
        return 1;
    }else if(n==1){
        return 1;
    }else{
        return (fibo(n-1)+fibo(n-2));
    }
}
