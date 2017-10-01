#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int>::iterator one,two;
int main()
{
    int n,x;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> x,mp[x]++;
    one = mp.begin();
    two = ++mp.begin();
    if(mp.size() == 2 && one->second == two->second)
        printf("YES\n%d %d\n",one->first,two->first);
    else
        printf("NO\n");
    return 0;
}
