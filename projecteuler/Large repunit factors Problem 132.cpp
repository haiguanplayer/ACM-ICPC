#include<bits/stdc++.h>
using namespace std;

const int N = 10000005;
int prime[N],flag[N],num=0;
void Init()//ËØÊı´ò±í
{
    for(int i=2;i<N;i++)
    {
        if(flag[i])
            continue;
        //printf("%d\n",i);
        prime[num++]=i;
        for(int j=2;i*j<N;j++)
            flag[i*j]=1;
    }
}

int pow_mod(int a,int b,int p)
{
    int ans = 1,base = a;
    while(b > 0)
    {
        if(b&1)
            ans = 1ll * ans*base % p;
        base = 1ll * base*base % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    Init();
    int k = 1e9;
    int cnt = 0,sum = 0;
    for(int i = 0;i < num;i++)
    {
        if(pow_mod(10,k,9*prime[i]) == 1)
        {
            cnt++;
            sum += prime[i];
            //printf("%d\n",sum);
            //break;
        }
        if(cnt == 40)
            return 0 * printf("%d\n",sum);
    }
    return 0;
}
