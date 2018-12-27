#include <stdio.h>


int print2d_2x3(int p[2][3]){
    /* least generic: fixed for 2x3 arrays */
    int x,y;
    for(x=0;x<2;x=x+1){
        for(y=0;y<3;y=y+1){
            printf("%3d ",p[x][y]);
        }
        printf("\n");
    }
    return 0;
}

int print2d_3col(int p[][3],int rows){
    /* more generic: 3 col, rows are variable */
    int x,y;
    for(x=0;x<rows;x=x+1){
        for(y=0;y<3;y=y+1){
            printf("%3d ",p[x][y]);
        }
        printf("\n");
    }
    return 0;
}

int print2d_3colp(int (*p)[3],int rows){
    /* more generic: 3 col, rows are variable */
    int x,y;
    for(x=0;x<rows;x=x+1){
        for(y=0;y<3;y=y+1){
            printf("%3d ",p[x][y]);
        }
        printf("\n");
    }
    return 0;
}

int print2d(int *p,int rows,int cols){
    /* most generic: rows,cols are variable */
    int x,y;
    for(x=0;x<rows;x=x+1){
        for(y=0;y<cols;y=y+1){
            printf("%3d ",p[x*cols + y]);
        }
        printf("\n");
    }
    return 0;
}


int main(void) {
    int arr2d[2][3];
    int x=0, y=0;
    int i=0;
    int r=0;
    
    i=0;
    for(x=0;x<2;x=x+1){
        for(y=0;y<3;y=y+1){
            arr2d[x][y]=i;
            i=i+1;
        }
    }
    printf("Method A\n");
    r=print2d_2x3(arr2d);
    
    printf("Method B-1\n");
    r=print2d_3col(arr2d,2);
    
    printf("Method B-2\n");
    r=print2d_3colp(arr2d,2);
    
    printf("Method C-1\n");
    r=print2d(&(arr2d[0][0]),2,3);
    
    printf("Method C-2\n");
    r=print2d((int *)arr2d  ,2,3);
    
    return 0;
}

