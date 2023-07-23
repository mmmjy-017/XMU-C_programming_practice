#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5 

typedef struct STU
{
	int num;
	struct STU *next;
	
}COU; 

COU *create()  //创建
{
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	printf("输入升序数列\n");
	for(int i=1; i<=N; i++)
	{
		tem = (COU*)malloc(sizeof(COU));
	    scanf("%d",&tem->num);
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

void insert(COU *head, int x)  //插入
{
	COU *p1 = head->next;
	COU *p2;
	COU *in = (COU*)malloc(sizeof(COU));	
	in->num = x;
	
	if(x < p1->num)       //是最小数的情况
	{
	  in->next = head->next;
	  head->next = in;
	}
	else
	{
		while(p1->num < x && p1!= NULL)  //找插入位置
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p1==NULL) p2->next = in;  //尾结点的情况
		else
		{
			in->next = p2->next;   //通常情况的插入
			p2->next = in;
		}
	}
	return;		
}
void print(COU *p)   //打印输出
{
	while(p!= NULL)
	{
		p = p->next;
		printf("%d ",p->num);
	}	
    return;
}
int main()
{
  COU *head;
  int insert_num;	
  head = create();
  printf("插入：\n"); 
  scanf("%d",&insert_num);
  insert(head,insert_num); 
  print(head);
  return 0;
}  
