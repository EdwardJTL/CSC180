#include <stdio.h>

int swap(int *a, int* b);
int bubblesort(int* a, int b);

int main(void) {
  int a[10]={3123,4,231212,123,12452,674,-3249,-2342,12414,663};
  int r;
  r = bubblesort(a,10);
  for (r = 0; r < 10; r++) {
    printf("%d\n", a[r]);
  }
  return 0;
}

int swap(int *a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return 0;
}
int bubblesort(int* a, int b){
  if (a == NULL) {
    return -1;
  }else if (b<1) {
    return -1;
  }else{
    int swapped = 1;
    while (swapped==1){
      int i;
      swapped = 0;
      for (i=1;i<b;i++){
        if (a[i-1]<a[i]) {
          int r;
          r = swap(&(a[i-1]),&(a[i]));
          swapped = 1;
        }
      }
    }
  }
  return 0;
}
