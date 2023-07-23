#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

COU *head1, *head2;

COU *create() { //创建链表
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	int len;
	printf("请输入链表长度：");
	scanf("%d", &len);
	printf("请输入链表a\n");
	for(int i = 0; i < len; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *edit(COU *head1) {

	COU *p, *q, *pre;
	

	pre = head1;   //要删的节点的前一个点
	p = head1->next;  //计入和的第一个点
	if(p == NULL) return head1;  //空链表
	q = p->next;
	if(q == NULL) return head1;  //只有一个数
	
	int sum = 0;

	while(1) {
		sum = p->val;
		while(q != NULL) {
			sum += q->val;//printf("%d\n", sum);
			if(sum == 0) {
              //printf("%d %d %d", pre->val, p->val, q->val);
				pre->next = q->next;
				p = pre->next;
				if(p == NULL) break;
				q = p->next;
				sum = p->val;
			} else
				q = q->next;
			
		}
		pre = p;
		if(pre == NULL) break;  //链表没有输出的可能原因：NULL->next;
		p = p->next;
		if(p == NULL) break;
		q = p->next;
	}

	return head1;
}

void print(COU *p) {
	printf("结果为：\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}


int main() {
	head1 = create();                       //创建链表a

	head2 = edit(head1);

	print(head2);
	return 0;
}
