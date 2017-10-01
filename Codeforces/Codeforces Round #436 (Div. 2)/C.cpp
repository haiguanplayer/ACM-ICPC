#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,f,k;
    cin >> a >> b >> f >> k;
    int st,ed;
    int cur = b,ans = 0;
    for(int i = 1;i <= k;i++)
    {
        if(i&1)
            st = 0,ed = a;
        else
            st = a,ed = 0;
        if(cur < abs(f-st)) cur = b,ans++;
        if(cur < abs(f-st)) return 0 * printf("-1\n");
        cur -= abs(f-st);
        if(i != k)//不是最后一趟
        {
            if(cur < abs(ed-f)*2) cur = b,ans++;
            if(cur < abs(ed-f)*2) return 0 * printf("-1\n");
            cur -= abs(ed-f);
        }
        else
        {
            if(cur < abs(ed-f)) cur = b,ans++;
            if(cur < abs(ed-f)) return 0 * printf("-1\n");
            cur -= abs(ed-f);
        }
    }
    cout << ans << "\n";
    return 0;
}
