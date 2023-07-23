#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

struct student
{
	long num;
	float score;
	struct student *next;
};

struct student *del(struct student *head, long num)
{
	struct student *p1, *p2;
	if(head == NULL)               //如果链表为空
	{
		printf("\nlist null!\n");
		return head;
	}
	p1 = head;
	while(p1->num != num && p1->next != NULL)  //找数
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(p1->next == NULL) printf("找不到该数！\n");  //找不到的情况
	else {
	//	printf("\ndelete: %d\n",p1->num);
		p2->next = p1->next;              //删除并释放空间
		free(p1);
	}
	return head;
} 

struct student *create()   //创建
{
	
	struct student *end, *tem, *head ;
	head = (struct student*)malloc(sizeof(struct student));
	end = head;
	printf("输入数列\n");
	for(int i=1; i<=N; i++)
	{
		tem = (struct student*)malloc(sizeof(struct student));
	    scanf("%ld",&tem->num);
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

void print(struct student *p)     //输出
{
	puts("余下的数是：");
	while(p!= NULL)
	{
		p = p->next;
		printf("%ld ",p->num);
	}	
    return;
}

int main()
{
  long del_num;
  puts("要删除的数字是：");
  scanf("%ld", &del_num);
  
  struct student *head;

  head = create();
  head = del(head, del_num);
  
  print(head);
  return 0;
}  
