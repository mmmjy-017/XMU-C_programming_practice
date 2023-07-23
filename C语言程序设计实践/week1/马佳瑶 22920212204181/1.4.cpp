#include<stdio.h>

const int n = 5;
 
int main()
{ int num[5]={1,3,5,4,2};
  
  int *p;
  
  int max = 0;
  for(int i = 0; i < n; ++ i) 
    if(num[i] > max){
    	max = num[i];
    	p = num + i; 
	}
   int t = *p;
   *p = num[n - 1];
   num[n - 1] = t;
   
   for(int i = 0; i < n; ++ i) printf("%d ", *(num + i));
  return 0;
}
