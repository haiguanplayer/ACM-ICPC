//only need count single character ,because it want max
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

char str[100005];
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",str);
        map<char,int> m;
        int len = strlen(str);
        int maxn = -99999999;
        for(int i = 0;i < n;i++)
        {
            m[str[i]]++;
            maxn = max(maxn,m[str[i]]);
        }
        printf("%d\n",maxn);
    }
    return 0;
}
