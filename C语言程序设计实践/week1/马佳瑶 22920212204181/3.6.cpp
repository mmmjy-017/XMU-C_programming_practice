#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct S {
	int a : 3;
	int b : 5;
	int c : 6;
	int d : 9;
}st;


int main() {
	
	st.a = 95; st.b = 25; st.c = 25; st.d = 105;
	
	printf("%10d %10d %10d %10d\n", st.a, st.b, st.c, st.d);
	printf("%10x %10x %10x %10x\n", st.a, st.b, st.c, st.d);
	
	char s1[30], s2[30], s3[30], s4[30];
	itoa(st.a, s1, 2);
	itoa(st.b, s2, 2);
	itoa(st.c, s3, 2);
	itoa(st.d, s4, 2);
	printf("%s\n %s\n %s\n %s\n", s1, s2, s3, s4);
	
	return 0;
}
