#include <stdio.h>
#include <stdlib.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out){
    if (matrix == NULL) {
        return -1;
    }
    if (matrix_out==NULL) {
        return -1;
    }
    int i;
    int c;
    for (i=0; i<rows; i+=1) {
        for (c=0; c<cols; c++) {
            matrix_out[i*cols+c] = matrix[i*cols+c];
        }
    }
    int current_row = 0;
    int current_col = 0;
    while ((current_row<rows)&&(current_col<cols)) {
        float max_entry = matrix_out[current_row*cols+current_col];
        if (max_entry<0) {
            max_entry = 0-max_entry;
        }
        int max_row;
        max_row = current_row;
        int r;
        for (r=current_row+1; r<rows; r+=1) {
            float check_entry;
            check_entry = matrix_out[r*cols+current_col];
            if (check_entry<0) {
                check_entry = 0-check_entry;
            }
            if (check_entry>max_entry) {
                max_entry = check_entry;
                max_row = r;
            }
        }
        if (max_entry *100000 > 1) {
            int k;
            for (k=0; k<cols; k+=1) {
                float temp;
                temp = matrix_out[current_row*cols+k];
                matrix_out[current_row*cols+k] = matrix_out[max_row*cols+k];
                matrix_out[max_row*cols+k] = temp;
            }
            float multiplier;
            multiplier = 1.0/matrix_out[current_row*cols+current_col];
            for (k=0; k<cols; k+=1) {
                matrix_out[current_row*cols+k] = matrix_out[current_row*cols+k]*multiplier;
            }
            for (r = current_row+1; r<rows; r+=1) {
                multiplier = matrix_out[r*cols+current_col];
                for (k=0; k<cols; k+=1) {
                    matrix_out[r*cols+k] = matrix_out[r*cols+k]-(matrix_out[current_row*cols+k]*multiplier);
                }
            }
            current_col+=1;
            current_row+=1;
        }
        else{
            current_col+=1;
        }
    }
    return 0;
}

int ge_bw(float *matrix, int rows, int cols, float *matrix_out){
    if (matrix == NULL) {
        return -1;
    }
    if (matrix_out==NULL) {
        return -1;
    }
    int i;
    int c;
    int n;
    for (i=0; i<rows; i+=1) {
        for (c=0; c<cols; c++) {
            matrix_out[i*cols+c] = matrix[i*cols+c];
        }
    }
    int r;
    for (r=rows-1; r>0; r-=1) {
        for (c=1; c<cols; c+=1) {
            if (matrix_out[r*cols+c]==1) {
                for (i=0; i<r; i+=1) {
                    float multiplier = matrix_out[i*cols+c];
                    for (n=0; n<cols; n+=1) {
                        matrix_out[i*cols+n]=matrix_out[i*cols+n]-matrix_out[r*cols+n]*multiplier;
                    }
                }
            }
        }
    }
    return 0;
}
