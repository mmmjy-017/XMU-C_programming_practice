#include<stdio.h>
#include<math.h>

int a[15][15];

int main(){
	int n, b, m;
	scanf("%d%d%d", &n, &b, &m);
	puts("输入矩阵：");
	for(int i = 0; i < n; ++ i)
	  for(int j = 0; j < n; ++ j)
	    scanf("%d", &a[i][j]);
	puts("转换结果为：");
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			printf("%d ", (int)pow(a[i][j], b) % m);
		}
		puts("");
	}    
	return 0;
}
