#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 100005;
string s[N];
int num[30],vis[30];
long long fac[N] = {1};

struct node
{
    int cnt[N];
    int id;
    bool operator < (const node & p)
    {
        for(int i = N-1;i >= 0;i--)
            if(cnt[i] != p.cnt[i])
                return cnt[i] > p.cnt[i];
    }
}p[30];
int main()
{
    for(int i = 1; i < N; i++)
        fac[i] = fac[i-1]*26%MOD;
    int n,ca = 0;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < 26; ++i)
        {
            vis[i] = 0;
            for(int j = 0;j < N;j++)
                p[i].cnt[j] = 0;
            p[i].id = i;
        }
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            int l=s[i].size();
            if(l>1) vis[s[i][0]-'a']=1;
            for(int k=l-1,j=0; k>=0; k--,j++)
            {
                int t=s[i][k]-'a';
                p[t].cnt[j]++;
            }
        }
        for(int i=0; i<26; i++)
            for(int j=0; j<=N; j++)
            {
                p[i].cnt[j+1]+=p[i].cnt[j]/26;
                p[i].cnt[j]%=26;
            }
        sort(p,p+26);
        for(int i=25; i>=0; i--)
            num[p[25-i].id]=i;
        int t=25;
        while(vis[p[t].id]&&t)//判断有没有出现前导0，如果出现的话，就更改赋值的顺序
        {
            swap(num[p[t].id],num[p[t-1].id]);
            t--;
        }
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            int l=s[i].size();
            for(int j=0; j<l; j++)
                ans=(ans+num[s[i][j]-'a']*fac[l-1-j]%MOD)%MOD;
        }
        printf("Case #%d: %lld\n",++ca,ans);
    }
    return 0;
}
