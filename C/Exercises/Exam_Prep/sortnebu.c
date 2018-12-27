#include <stdio.h>

int bubbleSort(float *A, int size) {
   int swapped = 0;
   float tmp = 0;
   int i = 0;
   int n = 0;

   n = size;
   while (1) {
      swapped = 0;
      for(i=1;i<n;i=i+1){
      /*for(i=1;i<=n-1;i=i+1){*/ /* also OK */
         if (A[i-1] < A[i]) {
            tmp = A[i];
	    A[i]=A[i-1];
	    A[i-1]=tmp;
	    swapped = 1;
	 }
      }
      if (swapped == 0) { break; }
   }
   return 0;
}

int main(void){
   float array[]={3123,4,231212,123,12452,674,-3249,-2342,12414,663};
   int r;
   int i;

   r=bubbleSort(array,10);
   for(i=0;i<10;i=i+1){
	   printf("%f\n",array[i]);
   }
   return 0;
}
