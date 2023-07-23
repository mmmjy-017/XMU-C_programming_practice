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
	printf("去重复数结果为：\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}

void del(COU *pre) {
	COU *mid = pre->next, *end = mid->next;  //pre是重复数字的前一个，end是重复数字的后一个
	if(mid == NULL || end == NULL) return;    //空链表和只有一个结点的情况

	while(1) {
		while(mid->val == end->val){
			end = end->next;
			if(end == NULL) break;    //当end为NULL时要退出，否则末位有重复数字会出错
		} 
		if(mid->next != end) {    //出现重复的情况
			while(mid != end) {
				pre->next = mid->next;
				free(mid);
				mid = pre->next;
			}
		}else{                //没有重复就全体右移
			pre = mid;
			mid = end;
		}
		if(mid == NULL) break; //边界
		end = end->next;
		if(end == NULL) break;//printf("%d %d %d\n", pre->val, mid->val, end->val);
		//print(head1); 
		//puts("****");
		
	}
	//print(head1);
	return;
}



int main() {
	printf("请输入链表a\n");
	head1 = create();                       //创建链表a
	del(head1);

	print(head1);
	return 0;
}
