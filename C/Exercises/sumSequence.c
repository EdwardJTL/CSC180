#include <stdio.h>
int sumSequence(int n);

int main(void) {
  int r;
  int i;
  for (i=1;i<10;i++){
    r = sumSequence(i);
    printf("r is %d\n",r);
  }
  return 0;
}

int sumSequence(int n) {
   int i;
   int neg = 0;
   int sum = 0;
   int period = 1;
   int cnt = 0;

   for(i=1;i<=n;i=i+1) {
      if (neg) {
         sum = sum - i;
         if (cnt == (period-1)) {
            neg = 0;
            cnt = 0;
            period = period + 1;
         } else {
            cnt = cnt + 1;
         }
      } else {
         sum = sum + i;
         if (cnt == (period-1)) {
            neg = 1;
            cnt = 0;
         } else {
            cnt = cnt + 1;
         }
      }
   }
   return sum;
}


/*int sumSequence(int n){
  if (n<1){
    return -1;
  }
  else if (n==1) {
    return 1;
  }else{
    int signid;
    int i;
    int rpt;
    int r;
    int k;
    signid = 1;
    i = 1;
    rpt = 0;
    r = n;
    while (r>0){
      if (rpt == 0) {
        for (k=0;(k<=i)&&(r>0);k++){
          r -= k;
        }
        rpt = 1;
        signid = 1;
      }else if (rpt==1) {
        for (k=0;(k<=i)&&(r>0);k++){
          r -= k;
        }
        i+=1;
        rpt = 0;
        signid = 0;
      }
    }
    if (signid == 0) {
      int result;
      result = sumSequence(n-1)-n;
      return result;
    }else if(signid==1){
      int result;
      result =sumSequence(n-1)+n;
      return result;
    }
  }
}*/
