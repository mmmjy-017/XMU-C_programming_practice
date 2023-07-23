
#include<stdio.h>
#include<string.h>

 
int main(){
	char a[] = "I love China!";  //如果用字符数组，那开的数组大小就是字符串的大小 
	//printf("%d", sizeof(a));
	for(int i = sizeof(a) - 2; i >= 0; -- i) //最后一位是休止符 
	printf("%c", a[i]);  //不能用a + i 因为这是单个字符输出 但a + i是字符串 
	return 0;
}
