#include<bits/stdc++.h>
using namespace std;

const int N = 2016+5;
char str[N][N];
bitset<N> bs[2][N],tmp;

bool check(int n)
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(bs[0][i][j]){
                tmp = bs[1][j]&bs[1][i];
                if(tmp != bs[1][i])
                    return false;
            }
    return true;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%s",str[i]+1);
        for(int i = 1;i <= n;i++)
            bs[0][i].reset(),bs[1][i].reset();
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(str[i][j] == 'P')
                    bs[1][i][j] = bs[0][j][i] = 1;
        if(!check(n))
        {
            printf("N\n");
            continue;
        }
        for(int i = 1;i <= n;i++)
            bs[0][i].reset(),bs[1][i].reset();
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(str[i][j] == 'Q')
                    bs[1][i][j] = bs[0][j][i] = 1;
        if(!check(n))
        {
            printf("N\n");
            continue;
        }
        printf("T\n");
    }
    return 0;
}
