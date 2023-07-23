#include<stdio.h>
#include<string.h>

 
int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	
	for(int i = 0; s[i] != '\0'; ++ i){
		if(s[i] == 't'){
			s[i] = 'e'; ++ cnt;
		} 
		else if(s[i] == 'T'){
			s[i] = 'E'; ++ cnt;
		}
	} 
	puts("Ìæ»»ºóµÄ×Ö·û´®£º");
	puts(s); 

	printf("Ìæ»»¸öÊý£º");
	printf("%d", cnt);
	
	return 0;
}
