#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1005;
double p[N],f[N];
int main()
{
    int N,n,k,m;
    cin >> N;
    for(int ca = 1;ca <= N;ca++)
    {
        cin >> n >> k >> m;
        for(int i = 0;i < n;i++)
            scanf("%lf",&p[i]);
        memset(f,0,sizeof(f));
        f[1] = p[0];
        //µÝÍÆ
        for(int i = 2;i <= m;i++)
        {
            for(int j = 0;j < n;j++)
                f[i] += p[j]*pow(f[i-1],j);
        }
        printf("Case #%d: %.7lf\n",ca,pow(f[m],k));
    }
    return 0;
}
