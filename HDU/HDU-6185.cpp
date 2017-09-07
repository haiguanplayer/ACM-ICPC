#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int msize = 4;
struct Matrix
{
    ll a[msize][msize];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
};

Matrix Multi(Matrix p,Matrix q)
{
    Matrix tmp;
    for(int i = 0;i < msize;i++)
    {
        for(int j = 0;j < msize;j++)
        {
            tmp.a[i][j] = 0;
            for(int k = 0;k < msize;k++)
                tmp.a[i][j] += ( p.a[i][k]*q.a[k][j] + MOD) % MOD;
                tmp.a[i][j] %= MOD;
        }
    }
    return tmp;
}

Matrix Fast_Matrix(ll n)
{
    Matrix base;
    base.a[0][0] = 1;base.a[0][1] = 5;base.a[0][2] = 1;base.a[0][3] = -1;
    base.a[1][0] = 1;
    base.a[2][1] = 1;
    base.a[3][2] = 1;
    Matrix ans;
    ans.a[0][0] = ans.a[1][1] = ans.a[2][2] = ans.a[3][3] = 1;
    while(n > 0)
    {
        if(n & 1)
            ans = Multi(ans,base);
        base = Multi(base,base);
        n >>= 1;
    }
    return ans;
}

int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        if(n == 1)
            printf("1\n");
        else if(n == 2)
            printf("5\n");
        else if(n == 3)
            printf("11\n");
        else if(n == 4)
            printf("36\n");
        else
        {
            Matrix ans;
            ans.a[0][0] = 36;ans.a[1][0] = 11;ans.a[2][0] = 5;ans.a[3][0] = 1;
            printf("%lld\n",Multi(Fast_Matrix(n-4),ans).a[0][0]);
        }
    }
    return 0;
}
//1 5 11 36 95 281 781
