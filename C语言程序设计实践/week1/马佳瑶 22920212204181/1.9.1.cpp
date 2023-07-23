#include<stdio.h>

#define N 12

int fac(int n){
	if(n == 1) return 1;
	return n * fac(n - 1);
}
 
int main( )
{ 
  int m;
  float k;
  printf("input m:");
  scanf("%d",&m);
  
  k = fac(m);
  
  printf("result=%f",k);
}
