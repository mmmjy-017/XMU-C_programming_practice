#include<stdio.h>
#include<string.h>

//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

int res[100];  //不放全局变量会出错 

int *spiralOrder(int* matrix, int matrixRowSize, int matrixColSize)
{

    int c1 = 0, r1 = 0, rh = matrixRowSize - 1, ch = matrixColSize - 1, count = 0;
 
    while(1)
    {
        for(int j = c1; j <= ch; ++ j) res[count ++] = *(matrix + c1 * matrixColSize + j);
        if(++ r1 > rh) break;
        for(int i = r1; i <= rh; ++ i) res[count ++] = *(matrix + i * matrixColSize + ch);
        if(-- ch < c1) break;
        for(int j = ch; j >= c1; -- j) res[count ++] = *(matrix + rh * matrixColSize + j);
        if(-- rh < r1) break;
        for(int i = rh; i >= r1; -- i) res[count ++] = *(matrix + i * matrixColSize + c1);
        if(++ c1 > ch) break;
        
    }
//  for(int i = 0; i < 9; ++ i) printf("%d ", res[i]);
//  puts("");
    return res;
} 
int main(){
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int matrixRowSize=3,matrixColSize=3;
	int *returnnum=spiralOrder(a[0], matrixRowSize, matrixColSize);
	int *p;
	for(p=returnnum;p<returnnum+9;p++) 
    { 
		printf("%4d",*p); 
     } 
	return 0;
}
