#include<stdio.h>
#include<string.h>

//char tmp[15];
const char str[11] = "AEIOUaeiou";

char *chg(char *s, char *tmp) {
	int n = strlen(s);
	int j = 0;

	for(int i = 0; i < n; ++ i) {
		for(int k = 0; k < 10; ++ k) {
			if(s[i] == str[k]) {
				tmp[j ++] = s[i];
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
