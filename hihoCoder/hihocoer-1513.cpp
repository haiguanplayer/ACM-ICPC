#include<bits/stdc++.h>
using namespace std;

const int N = 30005;
int a[N][6],id[N][6];
bitset<N> dp[N][6],ans;//dp[i][j]��ʾ��j�ſαȵ�i��ͬѧ���θߵ�ͬѧ

int main()
{
    int n,x;
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= 5;j++)
                scanf("%d",&x),a[i][j] = x,id[x][j] = i;//��j�ſε�x����iͬѧ
        for(int i = 2;i <= n;i++)
        {
            for(int j = 1;j <= 5;j++)
            {
                dp[i][j] = dp[i-1][j];//�Ƚ��ȵ�i-1��ͬѧ�ߵķ��뼯��
                dp[i][j].set(id[i-1][j]);//�ٽ���i-1������
            }
        }

        for(int i = 1;i <= n;i++)
        {
            ans.set();
            for(int j = 1;j <= 5;j++)
                ans &= dp[a[i][j]][j];
            printf("%d\n",ans.count());
        }
    }
    return 0;
}
