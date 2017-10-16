/*
思路：合并两个集合时利用启发式合并，
枚举元素横扫的集合到元素多的集合，利用01背包思想暴力更新，
集合的和用bitset维护，用位运算实现，复杂度为O（nlogn）
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

bitset<N*100> a[N];
int f[N],g[N],d[N][N];
int getf(int x)
{
    return x == f[x] ? x : f[x] = getf(f[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,op,x,y;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        d[i][1] = x;
        a[i][0] = a[i][x] = 1;
        g[i] = 1;
        f[i] = i;
    }
    cin >> q;
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;
            x = getf(x);y = getf(y);
            if(g[y] > g[x])
                swap(x,y);
            f[y] = x;
            for(int i = g[y];i >= 1;i--)
                a[x] |= a[x]<<(d[x][++g[x]] = d[y][i]);
        }
        else
        {
            cin >> x;
            cout << a[getf(x)].count() << "\n";
        }
    }
}
