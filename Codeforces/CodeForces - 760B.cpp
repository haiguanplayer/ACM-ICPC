#include<iostream>
#include<cstdio>
using namespace std;

int n, m, k;
int cnt = 1,ans = 1;
int main()
{
    scanf("%d%d%d",&n,&m,&k);

    m -= n;
    if(m == 0)
        return 0 * printf("1\n");
    while(m > 0)
    {
        if(k + ans <= n)
            ++cnt;
        if(k - ans >= 1)
            ++cnt;
        m -= cnt;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
