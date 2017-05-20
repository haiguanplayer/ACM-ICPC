#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N],b[N],x[N],y[N];
vector< pair<int,int> > p;
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]),x[a[i]] = i;
    for(int i = 1;i <= n;i++)
        scanf("%d",&b[i]),y[b[i]] = i;
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == b[i])
            continue;
        ans += x[b[i]]-i;
        int j = x[b[i]];
        while(j != i)
        {
            int pos = j-1;
            while(y[a[pos]] < j)
                pos--;
            p.push_back(make_pair(pos,j));
            swap(a[pos],a[j]);
            x[a[pos]] = pos;
            x[a[j]] = j;
            j = pos;
        }
    }
    printf("%d\n",ans);
    int m = p.size();
    printf("%d\n",m);
    for(int i = 0;i < m;i++)
        printf("%d %d\n",p[i].first,p[i].second);
    return 0;
}
