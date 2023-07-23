#include<stdio.h>
#include<string.h>

char s[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satday", "Sunday"};

int main(){
	int week;
	scanf("%d", &week);
	char (*p)[10] = s;
	puts(*(p + week - 1));
	
	return 0;
}
