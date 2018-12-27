#include <stdio.h>
#include <math.h>

int printMatrix(float *p, int rows, int col);

int main(void){
    float mat[3][4];
    float i;
    int x,y;
    for (x=0; x<3; x+=1) {
        for (y=0; y<4; y+=1) {
            mat[x][y]= expf(i);
            i = i+1;
        }
    }
    int r = printMatrix((float*)mat,3,4);
    return 0;
}

int printMatrix(float *p, int rows, int col){
    int x = 0;
    int y = 0;
    for (x=0;x<rows;x+=1){
        for (y=0;y<col;y+=1){
            printf("%08f    ",p[x*col + y]);
        }
        printf("\n");
    }
    return 0;
}

