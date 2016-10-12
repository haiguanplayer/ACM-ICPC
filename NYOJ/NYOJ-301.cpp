//矩阵快速幂
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int Mod = 19999997;
const int M = 1000007;
const int N = 3;
ll t,b,c,n,f1,f2;
struct Matrix//矩阵
{
    ll line,cal;
    ll a[N+1][N+1];
    Matrix(){
        line = 3,cal = 3;
        a[0][0] = b; a[0][1] = 1; a[0][2] = 0;
        a[1][0] = t; a[1][1] = 0; a[1][2] = 0;
        a[2][0] = c; a[2][1] = 0; a[2][2] = 1;
    }
};

Matrix isit(Matrix x,ll c)  //矩阵初始化
{
    for(ll i = 0;i < N;i++)
        for(ll j = 0;j < N;j++)
            x.a[i][j] = c;
    return x;
}

Matrix Multi(Matrix x,Matrix s)  //矩阵乘法
{
    Matrix ans;
    ans.line = x.line,ans.cal = s.cal;
    ans = isit(ans,0);
    for(ll i = 0;i < x.line;i++)
    {
        for(ll j = 0;j < x.cal;j++)
        {
            for(ll k = 0;k < s.cal;k++)
            {
                ans.a[i][j] += x.a[i][k]*s.a[k][j];
                ans.a[i][j] = (ans.a[i][j]+M)%M;
            }
        }
    }
    return ans;
}
ll Fast_Matrix(ll n)  //矩阵快速幂
{
    if(n == 1)
        return f1;
    n -= 2;
    ll x = 1,f = n,ok = 1;
    Matrix ans,tmp,ch;
    ans.line = 1,ans.cal = 3;
    ans.a[0][0] = f2, ans.a[0][1] = f1 ,ans.a[0][2] = 1;
    while(n > 0)
    {
        if(n % 2)
        {
            ans = Multi(ans,tmp);
        }
        tmp = Multi(tmp,tmp);
        n /= 2;
    }
    return ans.a[0][0];
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&f1,&f2,&t,&b,&c,&n);
        printf("%lld\n",Fast_Matrix(n));
    }
    return 0;
}
