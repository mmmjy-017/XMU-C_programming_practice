#include<stdio.h>

const int n = 5;
 
int main(){
    int a[4];
	for(int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}    
	for(int i = 0; i < n - 1; ++ i){           //Ã°ÅÝÅÅÐò
		for(int j = 0; j < n - i - 1; ++ j){
			if(a[j] < a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		} 
	}
	for(int i = 0; i < n; ++ i) printf("%d ", a[i]);
    return 0;
}
