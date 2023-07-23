#include<stdio.h>
#include<string.h>

 
int main(){
	char a[50] = "I love ";  //用字符数组形式或者申请空间 否则无法实现 
	char b[] = "China";
	strcat(a, b);
	puts(a);
	return 0;
}
