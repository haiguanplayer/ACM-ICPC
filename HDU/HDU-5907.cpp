#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 100005;
char str[N];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s",str);
        int len = strlen(str);
        long long cnt = 0,ans = 0;
        for(int i = 0;i < len;i++)
        {
            if(str[i] == 'q')
                cnt++,ans += cnt;
            else
                cnt = 0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
