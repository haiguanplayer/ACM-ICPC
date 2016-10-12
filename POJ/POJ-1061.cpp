/*
扩展欧几里得算法
这是个纬线，是个圈，，，
假设跳了t次以后碰面，那么(x+m*t)-(y +n*t) = k*l
即(n-m)*t + l*k = x-y
就成了拓展欧几里得算法的形式
a = n-m,b = l,c = x-y
ax+by=c 有解的充要条件是 gcd(a,b)|c
然后就是求解集
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void GcdEx(ll a,ll b,ll &x,ll &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    ll x1,y1;
    GcdEx(b,a%b,x1,y1);
    x = y1;
    y = x1 - a/b*y1;
    return;
}

int main()
{
    long long x,y,m,n,l;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    long long a = n-m,b = b = l,c = x-y,d = gcd(a,b),p,q;

    if(c % d != 0)//c/gcd（a，b）！=0时没有整数解的
        cout<<"Impossible"<<endl;
    else
    {
        a/=d;
        b/=d;
        c/=d;
        GcdEx(a,b,p,q);
        p*=c;
        ll t = p%b;
        while(t<0)
            t+=b;
        cout<<t<<endl;
    }
    return 0;
}
