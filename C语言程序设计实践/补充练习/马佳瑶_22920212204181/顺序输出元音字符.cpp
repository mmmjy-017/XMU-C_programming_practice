#include<stdio.h>
#include<string.h>

const char str[11] = "AEIOUaeiou";  //定义常量字符串 用循环遍历 判断更方便

char *chg(char *s, char *tmp) {
	int n = strlen(s);
	int j = 0;

	for(int i = 0; i < n; ++ i) {
		for(int k = 0; k < 10; ++ k) {
			if(s[i] == str[k]) {
				tmp[j ++] = s[i];   //如果是元音则存入tmp字符数组
				break;
			}
		}
	}

	tmp[j] = '\0';

	return tmp;
}

int main() {
	char s[15], tmp[15];
	puts("输入字符串：");
	gets(s);
	puts("结果为：");
	puts(chg(s, tmp));

	return 0;
}
