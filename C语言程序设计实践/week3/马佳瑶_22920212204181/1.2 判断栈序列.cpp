#include<stdio.h>

int main(){
	char s[100];
	scanf("%s", s);
	int cnt = 0;
	bool flag = true;
	for(int i = 0; s[i] != '\0'; ++ i){
		if(s[i] == 'I') ++ cnt;
		else --cnt;
		if(cnt < 0){
			flag = false;
			puts("非法序列！");
			break;
		}
		//printf("%d\n", cnt);
	}
	if(flag) puts("合法序列！");
	return 0;
}
