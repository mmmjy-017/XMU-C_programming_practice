#include<stdio.h>

#define N 12
 
int main()
{ 
  int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23}; 
  
  for(int *p = a[0]; p < a[0] + 12; ++ p){
  	printf("%d ", *p);
  }

  return 0;
}
