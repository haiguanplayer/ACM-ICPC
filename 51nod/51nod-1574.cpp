#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N],b[N],x[N],y[N],vis[N];
//vector< pair<int,int> > p;
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++)
        scanf("%d",&b[i]),y[b[i]] = i;
    for(int i = 1;i <= n;i++)
        x[i] = y[a[i]];
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])
            continue;
        int j = i;
        while(!vis[j])
        {
            ans += abs(j-x[j]);
            vis[j] = 1;
            j = x[j];
        }
    }
    cout << ans/2 << endl;
    return 0;
}
