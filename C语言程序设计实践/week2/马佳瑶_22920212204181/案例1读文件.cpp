#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define SIZE 9

const int N = 3;
int ff, tax[SIZE], salary[N];
long right[SIZE], deduct[SIZE];
char name[N][10];

void disp() {
	double sal,s,taxx;
	int i;                                    //可考虑不用浮点数
	printf("请输入税前扣除额：");
	scanf("%d",&ff);
	printf("请输入月收入：");
	scanf("%lf",&sal);

	//<0会如何？
	s=sal-ff;
	if(s<=0) taxx=0;
	else {
		for(i = 0; i < SIZE - 1; ++ i) {            //用SIZE而不是具体值
			if(s < right[i + 1] ) {
				taxx=s*tax[i]/100-deduct[i];
				break;
			}                               //应该加break
		}
		if(i >= SIZE - 1) taxx=s*tax[8]/100-deduct[8];
	}
	printf("应纳个人所得税额是：%.2lf\n",taxx);
}

void disp1(FILE *fp1, FILE *fp2) {
	puts("员工纳税：");
	for(int j = 0; j < N; ++ j) {
		double sal = salary[j],s,taxx;
		int i;                                    //可考虑不用浮点数

		s=sal-ff;
		if(s<=0) taxx=0;
		else {
			for(i = 0; i < SIZE - 1; ++ i) {            //用SIZE而不是具体值
				if(s < right[i + 1]) {
					taxx=s*tax[i]/100-deduct[i];
					break;
				}                       //应该加break
				//printf("%d %d %d\n", right[i], tax[i], deduct[i]);
			}
			if(i >= SIZE - 1) taxx=s*tax[8]/100-deduct[8];
		}
		
		fprintf(fp1, "%2lf", taxx);
		
		printf("%s应纳个人所得税额是：%.2lf\n",name[j], taxx);
	}
}

int main() {
	//读文件
	FILE *fp1, *fp2;

	if ((fp1=fopen("d:\\TAX.bin","rb"))==NULL) {
		printf("\ncannot open file\n");
		exit(1);
	}
	if ((fp2=fopen("d:\\Salary.bin","rb"))==NULL) {
		printf("\ncannot open file\n");
		exit(1);
	}

	if (fread(right,sizeof(right[0]),SIZE,fp1)!=SIZE) {
		printf ("file read error\n");
		exit(1);
	}
	if (fread(tax,sizeof(tax[0]),SIZE,fp1)!=SIZE) {
		printf ("file read error\n");
		exit(1);
	}
	if (fread(deduct,sizeof(deduct[0]),SIZE,fp1)!=SIZE) {
		printf ("file read error\n");
		exit(1);
	}
	if (fread(name,sizeof(name[0]),N,fp2)!=N) {
		printf ("file read error\n");
		exit(1);
	}
	if (fread(salary,sizeof(salary[0]),N,fp2)!=N) {
		printf ("file read error\n");
		exit(1);
	}

	disp();                //调用计算并显示所得税程序
	disp1(fp1, fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
