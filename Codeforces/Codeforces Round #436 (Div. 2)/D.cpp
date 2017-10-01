#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N],cnt[N],v[N],vis[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i],cnt[a[i]]++;
    int num = 0;
    for(int i = 1;i <= n;i++)
        if(cnt[i] == 0)
            v[++num] = i;
    int p = 1;
    for(int i = 1;i <= n;i++)
    {
        if(cnt[a[i]] > 1)
        {
            if(v[p] < a[i] || vis[a[i]])
                cnt[a[i]]--,a[i] = v[p],p++;
            else
                vis[a[i]] = 1;
        }
    }
    cout<<num<<"\n";
    cout<<a[1];
    for(int i = 2;i <= n;i++)
        cout<<" "<<a[i];
    cout<<"\n";
    return 0;
}
