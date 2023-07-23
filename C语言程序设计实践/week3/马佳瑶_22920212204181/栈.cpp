#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100    //栈初始大小
#define STACKINCREMENT 10    //栈分配增量
#define OK 1              //栈函数返回代码
#define ERROR 0
#define OVERFLOW -2

typedef  int SElemType; //栈中元素类型为整型
typedef  int Status;
//栈函数返回值为一用整型值表示的状态


typedef struct {                 //栈指针结构体定义
	SElemType * base;         //栈底指针
	SElemType * top;           //栈顶指针
	int stacksize;                   //当前已分配空间数
} SqStack;                          //类型名

Status InitStack(SqStack *sp) {
	//参数是指向堆栈指针结构体的指针
	sp->base =  (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));                                //分配栈空间，置栈底指针

	if (!sp->base) exit(OVERFLOW);
	//分配失败则指针为空(0)，出错返回
	sp->top = sp->base;              //置栈顶指针等于栈底指针
	sp->stacksize = STACK_INIT_SIZE;                 //置栈大小值

	return OK;
}

Status Push(SqStack *sp,SElemType data) {
	//2个参数，1是SqStack指针，2是要压入的数
	if (sp->top - sp->base >= sp->stacksize)
		//若栈满追加存储空间
	{
		sp->base = (SElemType *)realloc(sp->base, (sp->stacksize + STACKINCREMENT)*sizeof(SElemType));

		if (!sp->base) exit(OVERFLOW);
		sp->top = sp->base + sp->stacksize;       //重置栈顶指针
		sp->stacksize += STACKINCREMENT; //修改栈大小值
	}                                        //*(sp->top)=data; (sp->top)++;
	*sp->top++ = data;    //数据入栈，栈顶指针后加1
	return OK;
}

Status Pop(SqStack *sp, SElemType *data)
//2个参数，1是SqStack指针，2是出栈数存放的地址
{
	if (sp->top == sp->base)
		return ERROR;     //若栈空，出错
	*data = *(--sp->top);//栈顶指针先减1，栈顶元素出栈。
	//(sp->top)--,*data=*(sp->top)
	return OK;
}

Status StackEmpty(SqStack *sp) {
	return sp->top == sp->base;
}                                      //空则返回1，不空则返回0


int main() {

}
