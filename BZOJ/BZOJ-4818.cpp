#include<bits/stdc++.h>
using namespace std;

const int MOD = 20170408;
const int N = 2*1e7+5;
const int P = 105;
int tot,prime[N],f[P];
bool not_prime[N];
struct arr
{
    int a[P][P];
}a,ans;

int n,m,p;

void get_prime(int n)
{
    not_prime[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!not_prime[i])
            prime[++tot] = i;
        for(int j = 1;j <= tot && i*prime[j] <= n;j++)
        {
            not_prime[i*prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}
void mul(arr &c,arr a,arr b)
{
    memset(c.a,0,sizeof(c.a));
    for (int i = 0;i < p;i++)
        for (int j = 0;j < p;j++)
            for (int k = 0;k < p;k++)
                c.a[i][j] = (c.a[i][j]+1ll*a.a[i][k]*b.a[k][j]%MOD)%MOD;
}
arr arr_pow_mod(arr x,int y)
{
    memset(ans.a,0,sizeof(ans.a));
    for(int i = 0;i < p;i++)
        ans.a[i][i]=1;
    while(y > 0)
    {
        if(y&1)
            mul(ans,ans,x);
        mul(x,x,x);
        y >>= 1;
    }
    return ans;
}
int solve()
{
    for(int i = 1;i < p;i++)
        for(int j = 0;j < p;j++)
            a.a[j][i] = a.a[(j-1+p)%p][i-1];
    a = arr_pow_mod(a,n-1);
    int res = 0;
    for(int i = 0;i < p;i++)
        res = (res + 1ll*f[i]*a.a[i][0]%MOD)%MOD;
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    get_prime(m);//获得m以内的素数

    for(int i = 1;i <= m;i++)
        f[i%p]++;
    for(int j = 1;j <= m;j++)
        a.a[(-j%p+p)%p][0]++;
    int s1 = solve();//所有的方案数

    memset(f,0,sizeof(f));
    memset(a.a,0,sizeof(a.a));
    for(int i = 1;i <= m;i++)
        if(not_prime[i])
            f[i%p]++;
    for(int j = 1;j <= m;j++)
        if(not_prime[j])
            a.a[(-j%p+p)%p][0]++;
    int s2 = solve();//不含素数的方案数
    printf("%d\n",(s1-s2+MOD)%MOD);
    return 0;
}

