#include<stdio.h>

const int n = 3;
 
int main()
{
   int a[3][3]={1,2,3,4,5,6,7,8,9};
   int b[3][3];
   
   for(int i = 0; i < n; ++ i)           //另设一个b数组储存转置后的矩阵
     for(int j = 0; j < n; ++ j){
     	b[j][i] = a[i][j];
	 }
	 
   for(int i = 0; i < n; ++ i){
     for(int j = 0; j < n; ++ j){
     	a[i][j] = b[i][j];
     	printf("%d ", a[i][j]);
    }
    printf("\n");
   }
  
   return 0;
}
