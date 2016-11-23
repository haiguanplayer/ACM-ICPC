/*
HDU 5512
题意：n个塔，除了a和b都坏了，Two monks, Yuwgna and Iaka，想要重建，Yuwgna先来，
谁不能重建了，谁就输了，重建i的方法前提是有两个塔p+q = i。
思路：重建的塔只能是
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}

int main()
{
    int t,n,a,b;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d%d",&n,&a,&b);
        printf("Case #%d: ",ca);
        int d = gcd(a,b);
        int cnt = 0,k = d;
        while(k <= n)
        {
            cnt++;
            k += d;
        }
        cnt -= 2;
        if(cnt % 2 == 0)
            printf("Iaka\n");
        else
            printf("Yuwgna\n");
    }
    return 0;
}
