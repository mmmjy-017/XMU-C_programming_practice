#include<stdio.h>

int main() {
	int x;
	
	scanf("%d", &x);
	
	unsigned i = 1 << 31;  //从int的最高位开始（是31不是32）
	
	for(; i; i >>= 1){  //每次往右移动一位（不要忘记等于号）
		printf("%d", x & i ? 1 : 0);  //如果该位是1则相与结果大于0（是实际数字）
	}

	return 0;
}
