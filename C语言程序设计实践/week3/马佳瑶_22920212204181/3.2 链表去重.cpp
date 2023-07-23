#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 7

typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

COU *head1;

COU *create() { //创建链表
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	for(int i = 0; i < N; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

void print(COU *p) {
	printf("去重结果为：\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}

void del(COU *pre, int x) {
	COU *p = pre->next;
	while(p != NULL) {
		if(p->val == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;  //p=p->next是错的
		} else {
			pre = p;
			p = p->next;
		}
		//print(head1);
	}

}



int main() {
	printf("请输入链表a\n");
	head1 = create();                       //创建链表a
	COU *p = head1->next;
	while(p != NULL) {
		del(p, p->val);   //从节点p开始，往后找到和p一样的数字并删去
		p = p->next;
		//printf("%d\n", p->val);
	}
	
	print(head1);
	return 0;
}
