#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

void Arr(int *array, int n){
    srand((int) time(0));         
	for(int i = 0; i < n; ++ i){
		array[i] = rand() % 100;
	}	
	for(int i = 0; i < n - 1; ++ i){
		for(int j = 0; j < n - i - 1; ++ j){
			if(array[j] > array[j + 1]) swap(&array[j], &array[j + 1]);
		}
	}
	return;
}
 
int main(){
	
	int n;
	int *array = NULL;
	
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int) * n);
	
	Arr(array, n);
	
	for(int *p = array; p < array + n; ++ p) printf("%d ", *p);
	
	return 0;
}
