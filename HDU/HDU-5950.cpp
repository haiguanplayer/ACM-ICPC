/*
jiangjie
http://blog.csdn.net/spring371327/article/details/52973534
code cankao
http://blog.csdn.net/hjt_fathomless/article/details/52974444
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 2147493647;

typedef struct Ma
{
    ll m[7][7];
}Matrix;
Matrix Mul(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int k = 0;k < 7;k++)
        for(int i = 0;i < 7;i++)
            for(int j = 0;j < 7;j++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]%MOD) % MOD;
    return c;
}

Matrix quick_mod(Matrix a,ll k)
{
    Matrix ans;
    for(int i = 0;i < 7;i++)
        for(int j = 0;j < 7;j++)
            ans.m[i][j] = (i == j);
    while(k)
    {
        if(k&1)
            ans = Mul(ans,a);
        a = Mul(a,a);
        k /= 2;
    }
    return ans;
}


Matrix temp = {1, 1, 0, 0, 0, 0, 0,
                 2, 0, 0, 0, 0, 0, 0,
                 1, 0, 1, 0, 0, 0, 0,
                 4, 0, 4, 1, 0, 0, 0,
                 6, 0, 6, 3, 1, 0, 0,
                 4, 0, 4, 3, 2, 1, 0,
                 1, 0, 1, 1, 1, 1, 1
                };
int main()
{
    int t;
    ll N,a,b;
    cin >> t;
    while(t--)
    {
        scanf("%lld%lld%lld",&N,&a,&b);
        if(N == 1)
        {
            printf("%lld\n",a);
            continue;
        }
        else if(N == 2)
        {
            printf("%lld\n",b);
            continue;
        }

        Matrix c = quick_mod(temp,N-2);
        ll ans = b*c.m[0][0]%MOD + a*c.m[1][0]%MOD;
        ans += 16*c.m[2][0] + 8*c.m[3][0] + 4*c.m[4][0] + 2*c.m[5][0] + c.m[6][0];
        printf("%lld\n",ans % MOD);
    }
    return 0;
}
