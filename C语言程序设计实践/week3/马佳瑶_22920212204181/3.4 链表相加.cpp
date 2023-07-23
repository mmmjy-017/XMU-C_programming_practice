#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

COU *head1, *head2, *head3, *head4;

COU *create() { //创建链表
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	int len;
	printf("请输入链表长度：");
	scanf("%d", &len);
	for(int i = 0; i < len; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *add(COU *p, COU* q) {
	int t = 0;

	COU *head, *mid, *end;
	head = (COU*)malloc(sizeof(COU));  //新建链表存储结果
	mid = head;

	while(p != NULL && q != NULL) {
		t += p->val + q->val;         //要考虑进位

		end = (COU*)malloc(sizeof(COU));
		end->val = t % 10;
		mid->next = end;
		mid = end;
		//puts("***");
		t /= 10;

		p = p->next;
		q = q->next;

	}
	while(p != NULL) {
		end = (COU*)malloc(sizeof(COU));
		end->val = p->val;
		if(t) {                  //考虑遗留进位
			end->val += t;
			t = 0;
		}
		mid->next = end;
		mid = end;
		p = p->next;
	}
	while(q != NULL) {
		end = (COU*)malloc(sizeof(COU));
		end->val = q->val;
		if(t) {
			end->val += t;
			t = 0;
		}
		mid->next = end;
		mid = end;
		q = q->next;
	}
	mid->next = NULL;          //结尾
	//puts("***");
	return head;
}

COU *reverse(COU *head) {
	COU *pre, *mid, *end;
	pre = head;
	mid = head->next;
	if(pre == NULL || mid == NULL) return head;
	end = mid->next;
	pre = NULL;     //因为头结点是不存数据的，所以直接当作结尾方便打印

	while(1) {
		mid->next = pre;     //逐个翻转
		if(end == NULL) break;
		pre = mid;
		mid = end;
		end = end->next;
	}
	head = mid;
	return head;
}

void print(COU *p) {
	printf("相加结果为：\n");
	while(p != NULL) {
		printf("%d",p->val);
		p = p->next;
	}
	return;
}


int main() {
	printf("请输入链表a\n");
	head1 = create();                       //创建链表a
	head2 = create();
	head3 = add(head1->next, head2->next);
	head4 = reverse(head3);
	print(head4);
	return 0;
}
