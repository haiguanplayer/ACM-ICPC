/*
˼·���ϲ���������ʱ��������ʽ�ϲ���
ö��Ԫ�غ�ɨ�ļ��ϵ�Ԫ�ض�ļ��ϣ�����01����˼�뱩�����£�
���ϵĺ���bitsetά������λ����ʵ�֣����Ӷ�ΪO��nlogn��
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
