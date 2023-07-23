#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU
{
	char xh[20];   //学号
	double score;  //分数
	struct STU *next;  
	
}COU; 
 

COU *create()   //创建链表
{
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	while(1)
	{
		tem = (COU*)malloc(sizeof(COU));
	    scanf("%s %lf",tem->xh,&tem->score);
	    if(tem->score == 0) break;
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

COU* merge(COU* a, COU *b)
{
	COU* head = (COU*)malloc(sizeof(COU));
	a = a->next;
	b = b->next;	
	COU *end = (COU*)malloc(sizeof(COU));
	end = head;
	while(a!=NULL && b!=NULL)
	{
		if(strcmp(a->xh, b->xh) < 0)  //当学号a小于学号b，串起a
		{
			end->next = a;
			end = a;
			a = a->next;
		}
		else                  //当学号b大于等于学号a，串起b
		{
		    end->next = b;
			end = b;
			b = b->next;	
		}
		
	}	
	
		if(a==NULL)   //当a到尾部的时候
		{
			while(b!=NULL)  //如果b还有剩余
			{
				end->next = b;
				end = b;
				b = b->next;
			}
		}
		else     //当b到尾部的时候
		{
			while(a!=NULL)   //如果a还有剩余
			{
				end->next = a;
				end = a;
				a = a->next;
			}
		}
		end->next = NULL;
    return head;
}

void print(COU *p)
{
	printf("合并结果为：\n");
	while(p!= NULL)
	{
		p = p->next;
		printf("%s %lf\n",p->xh, p->score);
	}	
    return;
}

int main()
{
  COU *head1, *head2, *head;
  printf("请输入链表a，以0表示结束\n");
  head1 = create();                       //创建链表a
  printf("请输入链表b，以0表示结束\n");
  head2 = create();                     //创建链表b
  head = merge(head1, head2); 
  print(head);
  return 0;
}  
