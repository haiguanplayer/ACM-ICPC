#include<cstdio>
#include<cstdlib>
using namespace std;

const int N = 1005;
int n;
int a[N][N],b[N][N],c[N][N];
int r[N],ans1[N],ans2[N];

void mul(int a[N],int b[N][N],int s[N])
{
    int tmp[N];
    for(int j = 1;j <= n;j++)
    {
        tmp[j] = 0;
        for(int k = 1;k <= n;k++)
            tmp[j] += a[k]*b[k][j];
    }
    for(int i = 1;i <= n;i++)
        s[i] = tmp[i];
}
bool same(int a[N],int b[N])
{
    for(int i = 1;i <= n;i++)
        if(a[i] != b[i])
            return false;
    return true;
}
int main()
{
    for(int i = 1;i <= 1000;i++)
        r[i] = rand();
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                scanf("%d",&a[i][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                scanf("%d",&b[i][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                scanf("%d",&c[i][j]);
        mul(r,a,ans1);
        mul(ans1,b,ans1);
        mul(r,c,ans2);
        if(same(ans1,ans2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
