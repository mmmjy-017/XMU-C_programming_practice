#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct guest_info {
	char  name[8];      //姓名
	int     sum;              //人数
	char  time[10];      //时间
	int     number;       //编号
	struct guest_info *next;
} GuestLink, *Pointer;

void Insert (Pointer *Head );   //插入
void Search( Pointer Head );    //查询
void Update( Pointer Head );   //修改
void Delete( Pointer *Head ); //删除
void Show( Pointer Head );      //显示


int main() {
	Pointer Head=NULL;
	int i;
	do {     //显示提示信息,“1...5,6退出”略
		scanf("%d", &i);                          //输入功能选择
		switch(i) {
			case 1:
				Insert(&Head);
				break;
			case 2:
				Search(Head);
				break;
			case 3:
				Update(Head);
				break;
			case 4:
				Delete(&Head);
				break;
			case 5:
				Show(Head);
				break;
			case 6:
				break;
			default:
				printf("错误，重选");
				break;
		}
	} while(i!=6);                                           //6则退出
	return 0;

}

//这个程序不限数量，不对！
void  Insert(Pointer *Head) {
	int in_number;
	Pointer p,q,r;
	scanf("%d", &in_number);                       //输入编号
	p=q=*Head;
	while(p!=NULL) {                          //查找，走到链尾
		if( p->number==in_number) {
			printf("已有");    //已有，不输入
			return;
		} else {
			q=p;    //q指向当前，p指向下一个
			p=p->next;
		}
	}
	r=( Pointer )malloc( sizeof( GuestLink ) );     //申请空间
	r->next=NULL;                                     //设置队尾指针域
	if(r==NULL) {
		printf("分配空间失败");    //应前移
		return;
	}
	if(q==NULL)                          //空表？
		*Head=r;                           //空表则新结点为头结点
	else {
		q->next=r;    //否则接入表尾
	}
	r->number=in_number;
	scanf("%s", r->name);       //输入信息
	scanf("%d", &r->sum);
	scanf("%s",r->time);          //应该有输入错误处理！
}


void Search(Pointer Head) {
	int number, flag=1;
	Pointer p=Head;
	printf("请输入编号");
	scanf("%d", &number);                            //输入编号
	while( p!=NULL && flag ) {
		if(p->number==number) {                  //有则显示
			printf("姓名：%s", p->name);

			printf("人数：%d", p->sum);
			printf("时间是：%s", p->time);
			flag=0;
		}              //flag可不可省？
		else   p=p->next;           //不是则指向下一结点
	}
	if( flag )      printf("没...");             //这样用就对了！
}


//应该先显示再修改
void Update(Pointer Head) {
	int number, flag=1;
	Pointer p=Head;
	printf("请输入编号");
	scanf("%d",  &number);                          //输入编号
	while( p!=NULL && flag ) {
		if( p->number==number ) {               //是则修改
			scanf("%s", p->name);
			scanf("%d", &p->sum);                    //书上漏&
			scanf("%s", p->time);
			flag=0;
		}                  //flag可不可省？
		else   p=p->next;           //不是则指向下一结点
	}
	if(flag)    printf("没....");
}

//缺点：删除花时间长。
void Delete(Pointer *Head) {
	int number, flag=1;
	Pointer p,q;
	printf("请输入编号");
	scanf("%d", &number);                                    //输入编号
	p=q=*Head;
	while( p!=NULL && flag ) {
		if( p->number==number) {                        //有则删除
			if(p==*Head) {
				*Head=p->next;
				free(p);
			} else              {
				q->next=p->next;
				free(p);
			}
			flag=0;
		}          //flag可不可省？
		else  {
			q=p;    //q指向当前,p指向下一结点
			p=p->next;
		}
	}
	if( flag )        printf("没...");      //这样用就对了
}


//行数多要换页
void Show(Pointer Head) {
	Pointer p=Head;
	printf("\n");
	printf("编号   姓名       人数    时间");
	while( p!=NULL ) {                                   //列表显示
		printf("%10d", p->number);
		printf("%12s", p->name);
		printf("%10d", p->sum);
		printf("%12s\n", p->time);
		p=p->next;                //指向下一结点
	}
}

