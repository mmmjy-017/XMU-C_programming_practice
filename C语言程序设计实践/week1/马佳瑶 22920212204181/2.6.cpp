#include<stdio.h>
#include<string.h>

 
int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	
	bool word = true;   //标记单词首字母 
	
	for(int i = 0; s[i] != '\0'; ++ i){  
		if(s[i] != ' ' && word){  //不是空格且是单词首字母 
			++ cnt;
			word = false;  //防止重复统计 
		}
		else if(s[i] == ' '){  //是空格则把标记量改为真 
			word = true;
		}
	}
	printf("单词个数：");
	printf("%d", cnt);
	
	return 0;
}
