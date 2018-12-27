#include <stdio.h>

float bsqrt(float x, float accuracy);

float absolute(float x);

int main(void){
    int i;
    for (i=0; i<10; i++) {
        float sqrt;
        sqrt = bsqrt((float)i, 0.001);
        printf("The sqrt of %d is %f.\n",i,sqrt);
    }
    return 0;
}

float bsqrt(float x, float accuracy){
    float answer;
    answer = x/2.0;
    while (absolute(answer*answer-x)>accuracy) {
        answer = 0.5*(answer+x/answer);
    }
    return answer;
}

float absolute(float x){
    if (x<0) {
        x = 0 - x;
    }
    return x;
}
