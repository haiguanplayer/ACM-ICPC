/*
���⣺����Ŀ�����д���f(x)��g(x)�н��㣬f(x)=sqrt(x),g(x)=k/x��x=k^(2/3)������ӽ�x�ķ���
��ĸnot be larger than 100000.
˼·�����֣���������[a/b,c/d]��ÿ����[(a+c)/(b+d)]�����֣�ֱ����ĸ����100000
*/
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;


int main()
{
    int T,k;
    cin >> T;
    while(T--)
    {
        cin >> k;
        ld x = pow((ld)k,(ld)2/3);
        int a = (int)x,b = 1,c = a+1,d = 1;
        if(1ll*a*a*a == 1ll*k*k)//k^(2/3)������
        {
            printf("%d/1\n",a);
            continue;
        }
        int u,v;//save
        if(fabs((ld)a/b - x) < fabs((ld)c/d - x))
            u = a,v = b;
        else
            u = c,v = d;
        int p = a+c,q = b+d;
        while(q <= 100000)
        {
            if(fabs((ld)p/q - x) < fabs((ld)u/v - x))
                u = p,v = q;//save
             if((ld)p/q < x)
                a = p,b = q;
             else
                c = p,d = q;
            p = a+c,q = b+d;
            p /= __gcd(p,q);
            q /= __gcd(p,q);
        }
        printf("%d/%d\n",u,v);
    }
    return 0;
}
