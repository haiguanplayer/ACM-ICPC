#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int a[N];
map<int,int> mp;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        mp.clear();
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]),mp[a[i]]++;
        int num = 0;
        for(int i = 1;i <= n;i++)
        {
            int one = i-1;
            int two = i-2;
            if(mp[one]&&mp[two]&&mp[i])
            {
                while(mp[one]&&mp[two]&&mp[i])
                {
                    mp[one]--;mp[two]--;mp[i]--;
                    num++;
                }
                num += mp[i]/2;
                mp[i] %= 2;
            }
            else
            {
                num += mp[i]/2;
                mp[i] %= 2;
            }
        }
        printf("%d\n",num);
    }
}
