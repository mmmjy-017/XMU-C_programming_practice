#include <stdio.h>
#include <string.h>
#include <math.h>

char str[42], s[40];


int main() {
	gets(str);
	int n = 0;

    for(int i = 0; str[i] != '\0'; ++ i){  //去掉空格
		if(str[i] != ' '){
			s[n ++] = str[i];
		}
	}
	
	if(s[0] == '1') printf("-");   //判断符号位
	
	int e = 0;
	for(int i = 1; i < 9; ++ i){        //计算指数位
		e = e * 2 + s[i] - '0';
	}
	e -= 127;
	
	int zs = 1;                    //因为IEEE标准制会去掉首位的1，所以这里初始值设置为1
	float xs = 0.0, ans = 0.0;     //zs是整数，xs是小数，ans存答案
	
	for(int i = 9; i < 9 + e; ++ i){    //整数处理
		zs = zs * 2 + s[i] - '0';
	}
	
	double w = 0.5;                     //注意不要用int
	for(int i = 9 + e; i < n; ++ i){    //小数处理
		xs += (s[i] - '0') * w;  
		w /= 2;
		
	}
	
	ans = zs + xs;
	
	printf("%f", ans);
	
	return 0;
}
