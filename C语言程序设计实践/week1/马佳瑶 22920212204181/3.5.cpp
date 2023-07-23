#include<stdio.h>
#include<string.h>
#include<math.h>

const char str[20] = "0123456789ABCDEF";


int main() {

	char s[17], ansx[4], s1[17];

	int ans = 0, tmp;
	bool flag = false;

	gets(s);
	strcpy(s1, s);

	for(int i = 0; i < 16; i += 4) {   //十六进制部分
		int tmp = 0;
		for(int j = 0; j < 4; ++ j) {
			if(s[i + j] == '1') {
				tmp += pow(2, 3 - j);
			}
		}
		ansx[i / 4] = str[tmp];
	}

	ansx[4] = '\0';  //两个字符串的存储地址是挨着的
	puts(ansx);
	strcpy(s, s1);


	//printf("%c\n", s[0]);

	if(s[0] == '1') {   //处理负数
		flag = true;
		if(s[15] == '1') s[15] = '0';
		else {
			s[15] = '1';
			int i = 14;
			while(s[i] = '0') s[i --] = '1';
			s[i] = '0';
		}
		for(int i = 0; i < 16; ++ i) s[i] = '0' + '1' - s[i];
	}
	//puts(s);

	for(int i = 0; i < 16; ++ i) {
		if(s[i] == '1')
			ans += pow(2, 15 - i);
	}
	if(flag) printf("-");
	printf("%d", ans);

	return 0;
}
