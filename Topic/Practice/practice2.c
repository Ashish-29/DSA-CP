#include<stdio.h>

void swap(int*x){
    *x=57;
}

void main(){
    
    int a,b;
    scanf("%d%d",&a,&b);

    printf("a=%d\nb=%d\n",a,b);
    swap(&a);
    printf("a=%d\nb=%d\n",a,b);

    return ;
}