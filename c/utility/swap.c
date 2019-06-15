#include <stdio.h>

void swap(int *pa, int *pb){
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

int main(){
  int a = 5, b = 10;
  swap(&a, &b);
  printf("%d %d", a, b);
  return 0;
}
