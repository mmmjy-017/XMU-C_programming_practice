#include<stdio.h>
#include<string.h>


int uniquePaths(int m, int n) {
  //补充函数，返回路径数
  
  if(m == 1 || n == 1) return 1;
  return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}
int main(){
	int m=3,n=2;
	int k=uniquePaths(m,n);
	printf("共有%d条路径",k);
	return 0;
}
