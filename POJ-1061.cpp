/*
��չŷ������㷨
���Ǹ�γ�ߣ��Ǹ�Ȧ������
��������t���Ժ����棬��ô(x+m*t)-(y +n*t) = k*l
��(n-m)*t + l*k = x-y
�ͳ�����չŷ������㷨����ʽ
a = n-m,b = l,c = x-y
ax+by=c �н�ĳ�Ҫ������ gcd(a,b)|c
Ȼ�������⼯
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

    if(c % d != 0)//c/gcd��a��b����=0ʱû���������
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
