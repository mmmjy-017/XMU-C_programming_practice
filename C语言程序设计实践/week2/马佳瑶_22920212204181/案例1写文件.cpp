#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define SIZE 9

const int N = 3;
int Js, tax[SIZE], salary[N];
long right[SIZE], deduct[SIZE];
char name[N][10];

void acceptdata(FILE *fp1, FILE *fp2) {

	for(int i=0; i<SIZE; i++) { 
		printf("Please enter data:");
		printf("¼¶Êý£º");
		scanf("%d", &Js);
		
		scanf("%ld",&right[i]);
		scanf("%d",&tax[i]);
		scanf("%ld",&deduct[i]);
		
	}
	for(int i = 0; i < N; ++ i) {
		printf("Please enter data:");
		scanf("%s%d", name[i], &salary[i]);
	}

	if (fwrite(right,sizeof(right[0]),SIZE,fp1)!=SIZE)
		printf ("file write error\n");
	if (fwrite(tax,sizeof(tax[0]),SIZE,fp1)!=SIZE)
		printf ("file write error\n");
	if (fwrite(deduct,sizeof(deduct[0]),SIZE,fp1)!=SIZE)
		printf ("file write error\n");
	if (fwrite(name,sizeof(name[0]),N,fp2)!=N)
		printf ("file write error\n");
	if (fwrite(salary,sizeof(salary[0]),N,fp2)!=N)
		printf ("file write error\n");
}

int main() {

	FILE *fp1, *fp2;

	if ((fp1=fopen("d:\\TAX.bin", "wb"))==NULL) {
		printf("\ncannot open file\n");
		exit(1);
	}

	if ((fp2=fopen("d:\\Salary.bin", "wb"))==NULL) {
		printf("\ncannot open file\n");
		exit(1);
	}
	acceptdata(fp1, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;

}
