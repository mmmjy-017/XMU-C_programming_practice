#include<stdio.h>

#define N 7
 
int main()
{ 
  int a[N]={1, 2, 3, 4, 11, 12, 13};
  
  int *p = a;
  
  for(int i = 0; i < N / 2; ++ i){
  	  int t = *(p + i);
  	  *(p + i) = *(p + N - 1 - i);
      *(p + N - 1 - i) = t;  
  }
  
  for(int *p = a; p < a + N; ++ p) printf("%d ", *p);
  
  return 0;
}
