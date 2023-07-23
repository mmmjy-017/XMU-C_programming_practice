#include<stdio.h>
#include<string.h>
#define N 12

char *strcat(char *s1, char *s2){
	char *s = s1;
	int i = sizeof(s1);
	
	for(int j = 0; s2[j] != '\0'; ++ j){
		s[i++] = s2[j];
	}
	
	s[i] = '\0';
	
	return s;
	
}


int main( )
{ 
  char str1[30] = "I learn ", *str2 = "C language.";
  char *s;
  
  s = strcat(str1,str2);//strcat函数的返回值是指针      
  printf("%s\n", s);  
}
