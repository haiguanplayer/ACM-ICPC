#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n&1)
        return 0 * printf("0\n");
    printf("1");
    for(int i = 2;i <= n-1;i++)
        printf(" %d",i);
    printf("\n");

    int s = n*3/2;
    int t = s-(n-1)-1;
    for(int i = 1;i < n-1;i++)
    {
        printf("%d ",t);
        t = s-i-t;
    }
    printf("1\n");
    return 0;
}
