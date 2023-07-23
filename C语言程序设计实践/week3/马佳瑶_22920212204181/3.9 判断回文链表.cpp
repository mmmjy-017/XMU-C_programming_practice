#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

int n;

COU* reverseList(COU* head) {
	
	COU *pre, *mid, *end;
	pre = head->next;
	mid = pre->next;
	end = mid->next;
	pre->next = NULL;
	while(1) {
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
	printf("请输入链表长度：");
	scanf("%d", &n);
	printf("请输入链表：\n");
	for(int i = 0; i < n; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}


//void print(COU *p) {  
//
//	while(p != NULL) {
//		printf("%d ",p->val);
//		p = p->next;
//	}
//	return;
//}

COU *cpy(COU *head1){
	COU *head2, *mid, *end, *p;
	p = head1->next;
	head2 = (COU*)malloc(sizeof(COU));
	mid = head2;
	while(p != NULL){
		end = (COU*)malloc(sizeof(COU));
		end->val = p->val;                   //复制
		p = p->next;
		mid->next = end;
		mid = end;
	}
	
	mid->next = NULL;
	
//	COU *q = head2->next;
//	printf("%d\n",q->val);puts("***");

	return head2->next;
}

bool check(COU *p, COU *q){	
	while(p != NULL){
	//printf("%d %d\n", p->val, q->val);
		if(p->val != q->val) return false;   //若不相同则返回false
		p = p->next, q = q->next;
	}
	return true;
}


int main() {
	COU *head1, *head2;
	
	head1 = create();  //创建链表
	
	if(n < 2) puts("true");  //只含1个数
	else if(n < 3){          //只含2个数
		COU *a = head1->next, *b = a->next;
		if(a->val != b->val) puts("false");
		else puts("true");
	}
	else{
		head2 = cpy(head1); //printf("%d\n",head2->val);  //将链表1复制到链表2
		head1 = reverseList(head1);     //反转链表1
		
		if(check(head1, head2)) puts("true");  //如果链表1和链表2相等，则是回文串
		else puts("false");
	}

	return 0;
}
