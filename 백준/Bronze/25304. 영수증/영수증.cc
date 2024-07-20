#include <stdio.h>

int main (void){
    int x; 
    scanf("%d",&x);
    int n;
    scanf("%d",&n);
    int total = 0;
    for(int i = 1;i<=n;i++){
        int a,b; scanf("%d %d",&a,&b);
        total += a*b;
    }
    if(total == x){
        printf("Yes");
    }
    else{
        printf("No");
    }
    
    
    return 0;
}