#include<stdio.h>

const int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //每月日期常量

struct Cal{
	int year, month, day;
}date;

int check(){  //闰年判断 是二月+1
	if(date.month > 2 && (date.year % 400 == 0 || date.year % 100 != 0 && date.year % 4 == 0))
	return 1;
	return 0;
}

int dy(){
	int sum = date.day;
	for(int i = 1; i < date.month; ++ i) sum += mon[i];
	sum += check();
	return sum;
}

int main( )
{
    puts("请输入年月日：");
    scanf("%d-%d-%d", &date.year, &date.month, &date.day);
    puts("天数为：");
    printf("%d", dy());

    return 0;
}
