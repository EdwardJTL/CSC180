#include <stdio.h>
#include <stdlib.h>

float genAngle(int n);
int find(char* a, int length_a, char* b, int length_b);
int fibo_re(int n, int m);
int fibo_it(int n, int m);
int list_push(int n, int* m, int length);
int sum_list(int* m, int length);
int productSequence(int n);

int main(void){
  int i;
  char* a="falkasdfkwjlkefalks";
  char* b="falka";
  for (i=1;i<10;i++){
    printf("The external angle of a %d sided regular polygon is %f degrees\n", i,genAngle(i));
  }
  printf("the comparison result is %d\n", find(a,20,b,6));
  for (i=0;i<10;i++){
    printf("fibo(%d,3) is %d\n", i, fibo_re(i,3));
  }for (i=0;i<10;i++){
    printf("fibo(%d,3) is %d\n", i, fibo_it(i,3));
  }
  for (i=1;i<10;i++){
    printf("the %dth element of the sequence is %d\n",i,productSequence(i));
  }
  return 0;
}

float genAngle(int n){
  float output;
  output = 360.0/n;
  return output;
}

int find(char* a, int length_a, char* b, int length_b){
  if (length_b>length_a) {
    return -1;
  }else{
    int i;
    int j;
    int correct;
    for (i=0;i<(length_a-length_b);i++){
      correct = 0;
      for (j=0;j<length_b;j++){
        if (a[i+j]==b[j]){
          correct+=1;
        }
      }
      printf("%d\n", correct);
      if (correct==length_b-1){
        return 0;
      }
    }
  }
  return -1;
}

int fibo_re(int n, int m){
  if (n<m) {
    return 1;
  }
  else{
    int result;
    int i;
    result = 0;
    for (i=1;i<=m;i++){
      result+=fibo_re(n-i,m);
    }
    return result;
  }
}

int list_push(int n, int* m, int length){
  int i;
  for (i=0;i<length-1;i++){
    m[i]=m[i+1];
  }
  m[length-1]=n;
  return 1;
}

int sum_list(int* m, int length){
  int i;
  int sum;
  sum =0;
  for (i=0;i<length;i++){
    sum += m[i];
  }
  return sum;
}

int fibo_it(int n, int m){
  if (n<m) {
    return 1;
  }
  int num[m];
  int i;
  int d;
  int result;
  for (i=0;i<m;i++){
    num[i] = 1;
  }
  for (i=m;i<=n;i++){
    result = sum_list(num,m);
    d = list_push(result, num, m);
  }
  return result;
}

int productSequence(int n){
  int product;
  int counter;
  int i;
  int period;
  int neg;
  neg = 1;
  counter = 0;
  period = 1;
  product = 1;
  for (i = 1; i <= n; i++) {
    if (neg==1) {
      product = product * (-1) *i;
      counter += 1;
      if (counter==period) {
        neg = 0;
        counter = 0;
      }
    }else{
      product = product *i;
      counter += 1;
      if (counter==period) {
        neg = 1;
        period += 1;
        counter = 0;
      }
    }
  }
  return product;
}
