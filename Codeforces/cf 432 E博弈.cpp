/*
题意：有n个数，每次可以选择一个素数p，和一个整数k
要求n个数中至少存在一个数x满足：( p^k | x )
然后将n个数中所有p^k能整除的数除以p^k
两个人轮流进行操作，无法操作的一方输，问初始局势的胜负态
思路:其实这场游戏可以分成若干个子游戏，即每个素数可以单独考虑胜负，
然后用dfs计算sg函数值，判断该状态是必胜态还是必败态。
然后将所有子游戏状态合并，看最终是谁胜利。
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
map<int,int> H;
int SG(int mask)
{
    if(H.count(mask))
        return H[mask];
    set<int> p;
    for(int i = 1;i <= 30;i++)
    {
        bool flag = false;
        int x = 0;
        for(int j = 1;j <= 30;j++)
        {
            if(mask >> j & 1)
                if(j < i)
                    x |= 1 << j;
                else
                {
                    flag = true;
                    x |= 1 << j - i;
                }
        }
        if(x % 2 == 1)
            x -= 1;
        if(x != mask && flag)
            p.insert(SG(x));
    }
    int res = 0;
    while(p.count(res))
        res++;
    return H[mask] = res;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    map<int,int> m;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&x);
        for(int j = 2;j * j <= x;j++)
        {
            if(x % j == 0)
            {
                int cnt = 0;
                while(x % j == 0)
                {
                    x /= j;
                    cnt++;
                }
                m[j] |= 1 << cnt;
            }
        }
        if(x > 1)
            m[x] |= 2;
    }
    H[0] = 0;
    int res = 0;
    for(auto it : m)
        res ^= SG(it.second);
    if(res)
        puts("Mojtaba");
    else
        puts("Arpa");
}
