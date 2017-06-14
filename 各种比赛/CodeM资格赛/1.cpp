#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1005;
int a[N],b[N];

int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)
        scanf("%d",&b[i]);
    int minn = 1000000000;
    for(int i = 1;i <= m-n+1;i++)
    {
        int sum = 0;
        for(int j = 1;j <= n;j++)
            sum += (b[i+j-1]-a[j])*(b[i+j-1]-a[j]);
        minn = min(minn,sum);
    }
    printf("%d\n",minn);
    return 0;
}
