#include <stdio.h>
int main(void){
	int a[101] = {},a1[101];
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		a[i] = i+1;
		a1[i] = i+1;
	}
	for(int i = 0;i<m;i++){
		int r1,r2,cnt = 0;
		scanf("%d %d",&r1,&r2);
		for(int k = r2-1;k>=r1-1;k--){
			int tmp = a1[r1-1+cnt];
			a[k] =  tmp;
			cnt++;	  
		}
		for(int j = r2-1;j>=r1-1;j--){
			a1[j] = a[j];
		}
	}
	
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	
	return 0;
}