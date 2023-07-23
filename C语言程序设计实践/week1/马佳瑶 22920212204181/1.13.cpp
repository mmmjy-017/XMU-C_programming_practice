#include<stdio.h>
#include<string.h>

void rotate(int* matrix, int matrixRowSize, int matrixColSize){
   //补充函数，实现原地旋转功能
   //先上下颠倒再转置
   for(int i = 0; i < matrixRowSize / 2; ++ i){
   	 for(int j = 0; j < matrixColSize; ++ j){
   	 	   int t = *(matrix + i * matrixColSize + j);
   	 	   *(matrix + i * matrixColSize + j) = *(matrix + (matrixRowSize - i - 1) * matrixColSize + j);
   	 	   *(matrix + (matrixRowSize - i - 1) * matrixColSize + j) = t;
		}
   }
   
   for(int i = 0; i < matrixColSize; ++ i){
   	for(int j = 0; j < i; ++ j){
   		int t = *(matrix + i * matrixColSize + j);
   	 	   *(matrix + i * matrixColSize + j) = *(matrix + j * matrixColSize + i);
   	 	   *(matrix + j * matrixColSize + i) = t;
	   }
   }
}

int main(){
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	rotate(a[0],3,3);
	  
	int *p; 
	for(p=a[0];p<a[0]+9;p++) 
    { 
		
		if((p-a[0])%3==0) printf("\n"); 

		printf("%4d",*p); 
     } 
	return 0;
}
