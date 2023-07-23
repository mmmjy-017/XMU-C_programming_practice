#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 13 

typedef struct YSF    //链表实现约瑟夫问题
{
	int num;
	struct YSF *next;
	
}COU; 

COU *create()   //创建链表
{
	COU *pre, *tem, *head;
	head = (COU*)malloc(sizeof(COU));  //头结点申请空间
	pre = head;                     //让结点与头结点处于同一位置
	for(int i=1; i<=N; i++)
	{
		tem = (COU*)malloc(sizeof(COU));   //临时变量申请空间
	    tem->num = i;                    //赋值
		pre->next = tem;                //指向
		pre = tem;                       //后移
	}
	pre->next = tem;
	return head;
}

void quit(COU *head)
{
	int tol = N;
	COU *p = head;
    COU *q;
	while(tol > 1)   //当前剩余人数
	{
		int cnt = 1;
		while(cnt < 3)  //报数移动
		{
			++cnt;	
		    q = p;
			p = p->next;
		}
		q->next = p->next;  //删除报到3的点
		free(p);         //释放空间
		p = q->next;    //新起点
		tol--;            //人数-1
	}
	printf("剩下的人是:\n");
	printf("%d", p->num);
	return;
}

int main()
{
  COU *head;	
  head = create();    //创建链表
  quit(head);        //约瑟夫
  
  return 0;
}  
