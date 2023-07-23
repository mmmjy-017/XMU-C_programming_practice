#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 7

typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;


COU* reverseList(COU* head) {
	if(head == NULL || head->next == NULL) return head;
	COU *pre, *mid, *end;
	pre = NULL;
	mid = head;
	end = head->next;
    while(1){
		mid->next = pre;       //修改指向
		if(end == NULL) break;   //当end为NULL时退出
		
		pre = mid;              //从左往右右移
		mid = end;
		end = end->next;
	}
	
	head = mid;
	return head;
}


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


void print(COU *p, COU *end) {  //因为还有没赋值的head，尾结点并不是NULL
	printf("反转结果为：\n");
	while(p != end) {
		printf("%d ",p->val);
		p = p->next;
	}
	return;
}

int main() {
	COU *head1, *head2;
	printf("请输入链表a\n");
	head1 = create();                       //创建链表a
	head2 = reverseList(head1);
	print(head2, head1);
	return 0;
}
