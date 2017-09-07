#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int L,R,l,r;

ll dp[40][40];
ll dp2[40][40];
int digit[40];

void init()
{
    memset(dp,0,sizeof dp);
    for(int i=2; i<=36; i++)
    {
        ll ans=1e9;
        int s=0;
        while(ans)
        {
            ans/=i;
            s++;
        }
        ans=i-1;
        dp[i][1]=ans;
        for(int j=2; j<=s; j++)
        {
            if(j%2==1)
                ans*=i;
            dp[i][j]=ans;
        }
        for(int j=1; j<=s; j++)
            dp2[i][j]=dp[i][j]/(i-1)*i;
        for(int j=2; j<=s; j++)
            dp[i][j]+=dp[i][j-1];
        dp2[i][0]=1;
    }
}

int get_digit(int n,int x)
{
    int len=0;
    while(x)
    {
        digit[++len]=x%n;
        x/=n;
    }
    return len;
}

ll solve(int n,int len)
{
    ll ans=0;
    int flag=1;
    ll sum;
    for(int j=1;j<=(len+1)/2;j++)
    {
        sum=ans;
        int i=len-j+1;
        if(i==len)
        {
            if(i>j)
                ans+=(digit[i]-1)*dp2[n][i-j-1];
            else
                ans+=(digit[i]-1)*dp2[n][i-j];
        }

        else
        {
            if(i>j)
                ans+=(digit[i])*dp2[n][i-j-1];
            else
                ans+=(digit[i])*dp2[n][i-j];
        }
        if(digit[i]>digit[j])
            flag=0;
        else if(digit[i]<digit[j])
            flag=1;
    }
    if(flag)
        ans++;
    return ans;
}

ll fun(int n,int x)
{
    if(x==0)
        return 0;
    int len=get_digit(n,x);
    return solve(n,len)+dp[n][len-1];
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        scanf("%d%d%d%d",&L,&R,&l,&r);
        ll ans=0;
        for(int i=l; i<=r; i++)
        {
            ll sum=(i-1)*(fun(i,R)-fun(i,L-1))+R-L+1;
            ans+=sum;
        }
        printf("Case #%d: %lld\n",ca,ans);
    }
    return 0;
}

