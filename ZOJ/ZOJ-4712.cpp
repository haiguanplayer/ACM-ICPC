#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;

int e_gcd(int a,int b,int &x,int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = e_gcd(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp-a/b*y;
    return ans;
}
int cal(int a,int m)
{
    int x,y;
    int gcd = e_gcd(a,m,x,y);
    if(1 % gcd != 0) return -1;
    x *= 1/gcd;
    m = abs(m);
    int ans = x%m;
    if(ans <= 0) ans += m;
    return ans;
}
int main()
{
    int T,a,n;
    cin >> T;
    while(T--)
    {
        scanf("%d%d",&a,&n);
        int res = cal(a,n);
        if(res == -1)
            printf("Not Exist\n");
        else
            printf("%d\n",res);
    }
    return 0;
}

