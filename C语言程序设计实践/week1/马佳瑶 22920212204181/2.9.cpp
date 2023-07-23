#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int N = 105;

int cmp(const void *a, const void *b){
	return strlen((char*)a) > strlen((char*)b);
}
 
int main(){
	char s[5][N];
	
	for(int i = 0; i < 5; ++ i) gets(s[i]);
	
	qsort(s, 5, sizeof(s[0]), cmp);
	
	char s1[N];
	
	for(int i = 0; i < 5; ++ i){
		if(strlen(s[i]) < 3) s1[i] = ' ';
		else s1[i] = *(s[i] + 2);
	}
	puts("ÐÂ×Ö·û´®ÊÇ£º"); 
	puts(s1);
	
	return 0;
}
