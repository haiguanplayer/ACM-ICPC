#include<bits/stdc++.h>
using namespace std;

const int N = 40005;
const int x = 19;
int m,n,pos;
char s[N];
unsigned long long H[N],xp[N],Hash[N];
int rk[N];

int cmp(const int & a,const int & b)
{
    return Hash[a] < Hash[b] || (Hash[a] == Hash[b] && a < b);
}
int check(int len)
{
    int c = 0;
    pos = - 1;
    for(int i = 0;i < n-len+1;i++)
    {
        rk[i] = i;
        Hash[i] = H[i] - H[i+len]*xp[len];
    }
    sort(rk,rk+n-len+1,cmp);
    for(int i = 0;i < n-len+1;i++)
    {
        if(i == 0 || Hash[rk[i]] != Hash[rk[i-1]])
            c = 0;
        if(++c >= m)
            pos = max(pos,rk[i]);
    }
    return pos >= 0;
}
int main()
{
    while(~scanf("%d",&m) && m)
    {
        scanf("%s",s);
        n = strlen(s);

        H[n] = 0;
        for(int i = n;i >= 0;i--)
            H[i] = H[i+1]*x + s[i] - 'a';
        xp[0] = 1;
        for(int i = 1;i <= n;i++)
            xp[i] = xp[i-1]*x;

        if(!check(1))
            printf("none\n");
        else
        {
            int left = 1,right = n+1,mid;
            while(right - left > 1)
            {
                mid = (left+right)>>1;
                if(check(mid))
                    left = mid;
                else
                    right = mid;
            }
            check(left);
            printf("%d %d\n",left,pos);
        }
    }
    return 0;
}
