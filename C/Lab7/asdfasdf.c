//
//  asdfasdf.c
//  
//
//  Created by Edward Luo on 2017-11-01.
//

#include <stdio.h>


while ((current_row<rows)&&(current_col<cols)) {
    float max_entry = matrix_out[current_row*cols+current_col];
    int max_row = current_row;
    int r;
    for (r=current_row+1; i<rows; i+=1) {
        float check_entry;
        check_entry = matrix_out[r*cols+current_col];
        if (check_entry<0) {
            check_entry = 0-check_entry;
        }
        if (max_entry<0) {
            max_entry = 0-max_entry;
        }
        if (check_entry>max_entry) {
            max_entry = check_entry;
            max_row = r;
        }
    }
    if (max_entry!=0) {
        int k;
        for (k=0; k<cols; k+=1) {
            float temp;
            temp = matrix_out[current_row*cols+current_col];
            matrix_out[current_row*cols+current_col] = matrix_out[max_row*cols+current_col];
            matrix_out[max_row*cols+current_col] = temp;
        }
        float multiplier;
        multiplier = 1.0/max_entry;
        for (k=0; k<cols; k+=1) {
            matrix_out[current_row*cols+current_col] = matrix_out[current_row*cols+current_col]*multiplier;
        }
        for (r = current_row+1; r<rows; r+=1) {
            multiplier = matrix_out[r*cols+current_col];
            for (k=0; k<cols; k+=1) {
                matrix_out[r*cols+k] = matrix_out[r*cols+k]-(matrix_out[current_row*cols+k]);
            }
        }
        current_col+=1;
        current_row+=1;
    }
    else{
        current_col+=1;
    }
}
