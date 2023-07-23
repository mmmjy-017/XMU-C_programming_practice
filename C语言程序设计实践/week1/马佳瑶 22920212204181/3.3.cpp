#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char str[] = "0123456789ABCDEF";

int main() {
	int x;
	char ans[10], cnt = 0;
	scanf("%d", &x);
	//printf("%d\n", x >> 4);
	
	while(x){
		int i = x & 15; //printf("%d\n", x);   //与15相与可以取出后四位
		ans[cnt ++] = str[i];
		x >>= 4; //printf("%d\n", x);   //右移四位处理后续
	}
	
	ans[cnt] = '\0';
	strrev(ans);      //翻转
	
	puts(ans);
	
	//printf("%x", x);
	return 0;
}
