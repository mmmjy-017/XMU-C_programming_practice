#include<stdio.h>

const int N = 10;

double aver;
int sum, maxp;

struct Student {
	int num;
	char name[20];
	int score[3];
} stu[N];

int max(int a, int b, int c){
	if(a < b) a = b;
	if(a < c) a = c;
	return a; 
}

void input() {
	int maxss = 0;
	for(int i = 0; i < N; ++ i) {
		scanf("%d %s", &stu[i].num, stu[i].name);
		scanf("%d %d %d", &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		sum += stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		int maxs = max(stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		if(maxs > maxss){
			maxss = maxs;
			maxp = i;
		}
	}
	return;
}

void print() {
	puts("\n  NO.      name      score1    score2    score3");
	for(int i = 0; i < N; ++ i) {
		printf("%5d%10s", stu[i].num, stu[i].name);
		printf("%10d%10d%10d\n", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	printf("Average = %.2f\n", sum * 1.0 / 3 / N);
	printf("The highest is : %d %s\n", stu[maxp].num, stu[maxp].name);
	printf("His scores are: %3d %3d %3d", stu[maxp].score[0], stu[maxp].score[1], stu[maxp].score[2]);
	return;
}

int main( ) {
	input();
	print();
	return 0;
}
