#include<cstdio>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a+b >= 10)
        printf("error\n");
    else
        printf("%d\n",a+b);
    return 0;
}
