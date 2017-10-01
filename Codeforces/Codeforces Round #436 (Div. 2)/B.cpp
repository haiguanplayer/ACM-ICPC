#include<bits/stdc++.h>
using namespace std;

char s[205];
map<int,int> mp;
int main()
{
    int n,x;
    cin >> n;
    cin >> s;
    int maxn = 0,tmp = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(mp[s[i]] == 0)
                tmp++;
            mp[s[i]]++;
        }
        else
        {
            maxn = max(maxn,tmp);
            tmp = 0;
            mp.clear();
        }
    }
    if(tmp)
        maxn = max(maxn,tmp);
    cout << maxn << "\n";
    return 0;
}
