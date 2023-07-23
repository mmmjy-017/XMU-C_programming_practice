#include<stdio.h>

const int N = 5;

struct Student {
	int num;
	char name[20];
	int score[3];
} stu[N];

void input() {
	for(int i = 0; i < N; ++ i) {
		scanf("%d %s", &stu[i].num, stu[i].name);
		scanf("%d %d %d", &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
	return;
}

void print() {
	puts("\n  NO.      name     score1    score2    score3");
	for(int i = 0; i < N; ++ i) {
		printf("%5d%10s", stu[i].num, stu[i].name);
		printf("%10d%10d%10d\n", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	return;
}

int main( ) {
	input();
	print();
	return 0;
}
