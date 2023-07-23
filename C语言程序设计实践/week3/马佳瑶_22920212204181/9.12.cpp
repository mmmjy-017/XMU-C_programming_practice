#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4

typedef struct STU {
	char xh[20];   //学号
	char name[20];  //姓名
	char sex[8];  //性别
	int  age;     //年龄
	struct STU *next;

} COU;


COU *create() { //创建链表
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	for(int i = 0; i < 4; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%s %s %s %d", tem->xh,tem->name,tem->sex, &tem->age);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *del(COU *head1, int x) {
	COU *p = head1->next;
	COU *pre = head1;
	while(p != NULL) {
		if(p->age == x) {
			pre->next = p->next;
			free(p);
			p = p->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
	return head1;
}

void print(COU *p) {
	printf("\n结果为：\n");
	while(p!= NULL) {
		p = p->next;
		printf("%s %s %s %d\n",p->xh, p->name, p->sex, p->age);
	}
	return;
}

int main() {
	COU *head1;
	printf("请输入学号、姓名、性别、年龄\n");
	head1 = create();                       //创建链表a

	int age_k;
	puts("\n请输入要删除的年龄：");
	scanf("%d", &age_k);
	head1 = del(head1, age_k);
	
	print(head1);
	return 0;
}
