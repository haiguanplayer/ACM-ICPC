#include<cstdio>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
         printf("1");
        for(int i = 2;i <= 233;i++)
            printf("0000001");
        printf("\n");
    }
}
