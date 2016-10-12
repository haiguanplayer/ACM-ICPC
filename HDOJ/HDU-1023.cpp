#include<iostream>
#include<cstdio>
using namespace std;
int a[105][105],b[105];
void Init()
{
    a[2][0] = 1;
    a[2][1]=2;
    a[1][0]=1;
    a[1][1]=1;
    int len=1;
    for(int i=3;i<101;i++)
    {
        int k = 0;
        for(int j = 1;j <= len;j++)
        {
            int t = a[i-1][j] * (4*i-2) + k;
            k = t / 10;
            a[i][j] = t % 10;
        }
        while(k)
        {
            a[i][++len] = k%10;
            k /= 10;
        }
        for(int j = len;j >= 1;j--)
        {
            int t = a[i][j] + k*10;
            a[i][j] =t / (i+1);
            k = t % (i+1);
        }
        while(!a[i][len])
            len--;
        a[i][0]=len;
    }
}

int main()
{
    Init();
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = a[n][0];i > 0;i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
    return 0;
}
