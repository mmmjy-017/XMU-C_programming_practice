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

int day_cnt, night_cnt, idx;
FILE *fp;

int main() {
	Pointer Head=NULL;
	int i;
	if((fp = fopen("d:\\Order.bin", "w+")) == NULL) {
		puts("can not open file!");
	}
	do {
		printf("\n1———插入(Insert)\n");
		printf("2———查询(Serch)\n");
		printf("3———修改(Update)\n");
		printf("4———删除(Delete)\n");
		printf("5———显示(Show)\n");
		printf("6———退出(Exit)\n");
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
				printf("错误选择！请重选");
				break;
		}
	} while(i!=6);

	int n = day_cnt + night_cnt;
	if((fwrite(Head, sizeof(GuestLink), n, fp)) != n) {
		puts("Can not write file!");
	}
	fclose(fp);                                         //6则退出
	return 0;

}

//这个程序不限数量，不对！
void  Insert(Pointer *Head) {
	Pointer p,q,r;

	p=q=*Head;
	while(p!=NULL) {                          //查找，走到链尾
		if( p->number==idx + 1) {
			printf("已有相同编号：");    //已有，不输入
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

	if(day_cnt >= MaxSize && night_cnt >= MaxSize) {
		puts("抱歉，预约已满！！");
		return;
	} else {
		++ idx;
		printf("当前编号为：%d\n", idx);
		r->number=idx;

		printf("请输入姓名：");
		scanf("%s", r->name);       //输入信息
		printf("请输入人数：");
		scanf("%d", &r->sum);
		printf("请输入用餐时间：");
		scanf("%s",r->time);          //应该有输入错误处理！

		if(strcmp(r->time, "18点") < 0) {
			if(day_cnt + 1 > MaxSize) {
				printf("该时间段已满，请另约时间\n");
				while(scanf("%s", r->time), strcmp(r->time, "18点") < 0) {
					printf("该时间段已满，请另约时间\n");
				}
			} else ++ day_cnt;
		} else {
			if(night_cnt + 1 > MaxSize) {
				printf("该时间段已满，请另约时间\n");
				while(scanf("%s", r->time), strcmp(r->time, "18点") >= 0) {
					printf("该时间段已满，请另约时间\n");
				}
			} else ++ night_cnt;
		}
	}
}


void Search(Pointer Head) {
	int flag=1;
	char name[30];
	Pointer p=Head;
	printf("请输入要查询的姓名：\n");
	scanf("%s", name);                            //输入编号
	while( p!=NULL && flag ) {
		if(strcmp(name, p->name) == 0) {                  //有则显示
			printf("姓名：%s\n", p->name);

			printf("人数：%d\n", p->sum);
			printf("时间是：%s\n", p->time);
			flag=0;
		}              //flag可不可省？
		else   p=p->next;           //不是则指向下一结点
	}
	if( flag )      printf("没有查询到！！\n");             //这样用就对了！
}


//应该先显示再修改
void Update(Pointer Head) {
	int flag=1;
	char name[30];
	Pointer p=Head;
	printf("\n请输入姓名：");
	scanf("%s", name);                          //输入编号
	while( p!=NULL && flag ) {
		if(strcmp(p->time, "18点") < 0) --day_cnt;
		else -- night_cnt;
		if( strcmp(name, p->name) == 0 ) {               //是则修改
			puts("原数据为：");
			printf("姓名：%s\n", p->name);
			printf("人数：%d\n", p->sum);
			printf("时间是：%s\n", p->time);

			puts("\n请输入新的数据：");
			scanf("%s", p->name);
			scanf("%d", &p->sum);                    //书上漏&
			scanf("%s", p->time);
			flag=0;
			if(strcmp(p->time, "18点") < 0) ++ day_cnt;
			else ++ night_cnt;
		}                  //flag可不可省？
		else   p=p->next;           //不是则指向下一结点
	}
	if(flag)    printf("没有找到要修改的记录！！");
}

//缺点：删除花时间长。
void Delete(Pointer *Head) {
	int flag=1;
	char name[30];
	Pointer p,q;
	printf("\n请输入姓名：");
	scanf("%s", name);                                    //输入编号
	p=q=*Head;
	while( p!=NULL && flag ) {
		if( strcmp(name, p->name) == 0) {  //有则删除
			flag=0;
			puts("将要删除的数据为：");
			printf("姓名：%s\n", p->name);
			printf("人数：%d\n", p->sum);
			printf("时间是：%s\n", p->time);
			puts("按1继续删除，按0放弃删除：");
			int k;
			scanf("%d", &k);
			if(k == 0) break;

			if(p==*Head) {
				*Head=p->next;
				free(p);
			} else              {
				q->next=p->next;
				free(p);
			}
			if(strcmp(p->time, "18点") < 0) --day_cnt;
			else -- night_cnt;

		}          //flag可不可省？
		else  {
			q=p;    //q指向当前,p指向下一结点
			p=p->next;
		}
	}
	if( flag )        printf("没有找到可以删除的数据！！");      //这样用就对了
}


//行数多要换页
void Show(Pointer Head) {
	Pointer p=Head;
	printf("\n");
	puts("\n午餐预约名单：\n");
	printf("        编号      姓名       人数       时间\n");
	while( p!=NULL ) {   //列表显示
		if(strcmp(p->time, "18点") < 0) {  //白天
			printf("%10d", p->number);
			printf("%12s", p->name);
			printf("%10d", p->sum);
			printf("%12s\n", p->time);
		}
		puts("");
		p=p->next;                //指向下一结点
	}
	p=Head;
	puts("\n晚餐预约名单：\n");
	printf("        编号      姓名       人数       时间\n");
	while( p!=NULL ) {   //列表显示
		if(strcmp(p->time, "18点") >= 0) {  //晚餐
			printf("%10d", p->number);
			printf("%12s", p->name);
			printf("%10d", p->sum);
			printf("%12s\n", p->time);
		}

		p=p->next;                //指向下一结点
	}
}
