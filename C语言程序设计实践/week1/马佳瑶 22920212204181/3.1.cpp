#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main() {
	char x=0xfe;   //-2
	int y=x>>1;
	printf("%d",y);
	
	return 0;
}
