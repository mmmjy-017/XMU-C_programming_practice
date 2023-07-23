#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU {
	char xh[20];   //学号
	char name[20];  //姓名
	struct STU *next;

} COU;


COU *create() { //创建链表
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	while(1) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%s %s", tem->xh,tem->name);
		if(strcmp(tem->xh, "0") == 0) break;
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *del(COU *head1, char s[]) {
	COU *p = head1->next;
	COU *pre = head1;
	while(p != NULL) {
		if(!strcmp(p->xh, s)) {
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
		printf("%s %s\n",p->xh, p->name);
	}
	return;
}

int main() {
	COU *head1, *head2;
	printf("请输入链表a，以0表示结束\n");
	head1 = create();                       //创建链表a
	printf("\n请输入链表b，以0表示结束\n");
	head2 = create();                     //创建链表b
	COU *p = head2->next;
	while(p != NULL) {

		head1 = del(head1, p->xh);
		p = p->next;

	}

	print(head1);
	return 0;
}
