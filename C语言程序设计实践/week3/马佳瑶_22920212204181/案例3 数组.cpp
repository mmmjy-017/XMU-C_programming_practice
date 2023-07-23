#include<stdio.h>
#define MaxSize 20

struct guest_info {
	char  name[8];     //姓名
	int     sum;             //人数
	char  time[10];     //时间
	int     number;       //编号
} GuestList[MaxSize];


void Insert( int * );   //插入
void Search( int );    //查询
void Update( int );   //修改
void Delete( int * ); //删除
void Show( int );      //显示

int main() {
	int i,  count=0;
	do {             //显示提示信息,“1...5,6退出”略
		scanf("%d", &i);                          //输入功能选择
		switch(i) {
			case 1:
				Insert( &count );
				break;
			case 2:
				Search( count );
				break;
			case 3:
				Update( count );
				break;
			case 4:
				Delete( &count );
				break;
			case 5:
				Show( count );
				break;
			case 6:
				break;
			default:
				printf("错误，重选");
				break;
		}
	} while( i!=6 );               //6则退出
	return 0;
}

void Insert(int *count) {
	int i, in_number;
	if(*count==MaxSize) {
		printf("满");    //满则不输入
		return;
	}
	scanf("%d", &in_number);                            //按编号输入
	for( i=0; i<*count; i++ )
		if(GuestList[i].number==in_number) {    //已有此编号
			printf("已有相同编号");    //则不输入
			return;
		}
	GuestList[i].number=in_number;          //i正好指向表尾
	scanf("%s", GuestList[i].name);
	scanf("%d", &GuestList[i].sum);
	scanf("%s", GuestList[i].time);
	(*count)++;                                   //订桌数加1
}

void Search(int count) {
	int i,  number,  flag=1;
	printf("请输入编号");
	scanf("%d",&number);                            //输入编号
	for(i=0; i<count && flag; i++) {
		if(GuestList[i].number==number) {    //有则显示
			printf("姓名：%s", GuestList[i].name);
			printf("人数：%d", GuestList[i].sum);
			printf("时间是：%s", GuestList[i].time);
			flag=0;
		}                //flag可省
		else                                 //这样写有没问题？
			printf("没有查询到！！");             //会如何显示？
	}                                       //后面链表程序写对
}

//应该先显示再修改
void Update(int count) {
	int i, number, flag=1;
	printf("请输入编号");
	scanf("%d",&number);                            //输入编号
	for(i=0; i<count && flag; i++) {
		if(GuestList[i].number==number) {    //有则修改
			scanf("%s", GuestList[i].name);        //书上漏
			scanf("%d", &GuestList[i].sum);
			scanf("%s", GuestList[i].time);
			flag=0;
		}           //flag可省
		else                               //这样写有没问题？
			printf("没有查询到可以删除的数据！！");
	}
}

//缺点：删除花时间长。
void Delete(int *count) {
	int i, j, number, flag=1;
	printf("请输入编号");
	scanf("%d",&number);                                    //输入编号
	for(i=0; i<*count && flag; i++) {
		if(GuestList[i].number==number) {           //有则删除
			for(j=i; j<*count-1; j++)             //后一元素向前移动
				GuestList[j]=GuestList[j+1];
			flag=0;                //flag可省
			(*count)--;
		} else                                //这样写有没问题？
			printf("没....");
	}
}

//行数多要换页
void Show(int  count) {
	int i;
	printf("\n");
	printf("编号   姓名   人数  时间");
	for(i=0; i<count; i++) {                    //列表显示
		printf("%10d", GuestList[i].number);
		printf("%12s", GuestList[i].name);
		printf("%10d", GuestList[i].sum);
		printf("%12s\n", GuestList[i].time);
	}
}






