#include<stdio.h>

const int n = 4;
 
int main()
{
 int a[ ][4]={0,1,2,3,1,4,5,6,2,5,7,8,3,6,8,9};
 int found=1;
 //判断方阵是否为对称阵，若不是，found置为0
 for(int i = 0; i < n; ++ i){
 	for(int j = 0; j < n; ++ j){
 		printf("%d ", a[i][j]);
	 }
	 puts("");
 }

 puts("");
 
 for(int i = 0; i < n; ++ i){
 	for(int j = 0; j < n; ++ j){
 		if(a[i][j] != a[j][i]){
 			found = 0;
 			break;
		 }
	 }
	 if(!found) break;
 }
 if (found==0)
   printf("no\n");
 else
   printf("yes\n");
return 0;}
