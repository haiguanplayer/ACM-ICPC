#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
char str[25];
inline int ch(char c){return c-'0';}
ll Getnum(int l,int r)
{
    ll ans = 0;
    for(int i = l;i <= r;i++)
        ans = ans * 10 + str[i] - '0';
    return ans;
}
int main()
{
    int t;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%s",str);
        printf("Case #%d: ",ca);
        int len = strlen(str);
        ll sum;//div = str[len-1]-'0';//,pos = len - 1;
        sum = ch(str[0]) + Getnum(1,len-4) - ch(str[len-3]) * ch(str[len-2]) / ch(str[len-1]);
        sum = max(sum,Getnum(0,len-5) + ch(str[len-4]) - ch(str[len-3]) * ch(str[len-2]) / ch(str[len-1]));

        if(len > 5)
        {
            int div = Getnum(len-2,len-1);
            sum = max(sum,ch(str[0]) + Getnum(1,len-5) - ch(str[len-4]) * ch(str[len-3]) / div);
            sum = max(sum,Getnum(0,len-6) + ch(str[len-5]) - ch(str[len-4]) * ch(str[len-3]) / div);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
