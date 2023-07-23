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

COU *edit(COU *head1, int x) {

	COU *head, *mid, *end;
	head = (COU*)malloc(sizeof(COU));
	if(head1->next == NULL) return head;
	mid = head;

	COU *p = head1->next;
	while(1) {                          //先串起小于x的数

		if(p->val < x) {
			end = (COU*)malloc(sizeof(COU));
			end->val =  p->val;
			mid->next = end;
			mid = end;
		}
		p = p->next;
		if(p == NULL) break;
		//puts("**");
	}
	p = head1->next;
	while(1) {                          //再串起大于等于x的数
	
			if(p->val >= x) {
				end = (COU*)malloc(sizeof(COU));
				end->val =  p->val;
				mid->next = end;
				mid = end;
			}
			p = p->next;
			if(p == NULL) break;
			//puts("**");
		}
	mid->next = NULL;
	return head;
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
	int x;
	head1 = create();                       //创建链表a
	printf("请输入分割基准x：");
	scanf("%d", &x);
	head2 = edit(head1, x);

	print(head2);
	return 0;
}
