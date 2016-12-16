#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1000005;
int prime[N],flag[N],num;
void Init()//ËØÊý´ò±í
{
    for(int i = 2;i < N;i++)
    {
        if(flag[i])
            continue;
        prime[num++] = i;
        for(int j = 2;i*j < N;j++)
            flag[i*j] = 1;
    }
}
int main()
{
    Init();
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        long long maxn = 1;
        for(int i = 0;prime[i] <= n;i++)
        {
            long long temp = prime[i];
            while(temp*prime[i] <= n)
                temp *= prime[i];
            maxn = max(maxn,temp);
        }
        printf("%lld\n",maxn*2);
    }
    return 0;
}
