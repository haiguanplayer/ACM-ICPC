/*
题解：http://blog.csdn.net/lixuepeng_001/article/details/50577932
题意：给你 a , b , c , d , k 五个值 （题目说明了 你可以认为 a=c=1）
x 属于 [1,b] ，y属于[1,d]  让你求有多少对这样的 （x,y）满足gcd（x,y）==k。
给你的时间是 3000 MS。   0 < a <= b <= 100,000, 0 < c <= d <= 100,000, 0 <= k <= 100,000
思路:gcd（x,y）=k   gcd（x / k,y / k）=1
所以x 属于 [1,b / k] ，y属于[1,d / k]
让你求有多少对这样的 （x,y）满足gcd（x,y）== 1 即x和y是互质的
F（d）为 有多少对（x,y）满足 gcd（x,y）== d 的倍数
f（d）为有多少对（x,y）满足 gcd（x,y）== d
F(x) = (b/x)*(d/x)  f(1) = mu(1)*F(1)+mu(2)*F(2)+...+
最后容斥下 G（b，d）- G（b，b）/ 2
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N];
int prime[N],mu[N];
int cnt;
void Init()
{
    memset(vis,false,sizeof(vis));
    memset(prime,0,sizeof(prime));
    memset(mu,0,sizeof(mu));
    cnt = 0;mu[1] = 1;
    for(int i = 2;i < N;i++)
    {
        if(!vis[i])
        {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0;j < cnt && i*prime[j] < N;j++)
        {
            vis[i*prime[j]] = true;
            if(i % prime[j])
                mu[i*prime[j]] = -mu[i];
            else
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
}
int main()
{
    Init();
    int t;
    scanf("%d",&t);
    for(int ca = 1;ca <= t;ca++)
    {
        int a,b,c,d,k;//a,c not be use
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k == 0)
        {
            printf("Case %d: 0\n",ca);
            continue;
        }
        b /= k;
        d /= k;
        long long ans1 = 0,ans2 = 0;
        //F(x) = (b/x)*(d/x)  f(1) = mu(1)*F(1)+mu(2)*F(2)+...+
        for(int i = 1;i <= min(b,d);i++)
            ans1 += 1ll*mu[i]*(b/i)*(d/i);
        for(int i = 1;i <= min(b,d);i++)
            ans2 += 1ll*mu[i]*(min(b,d)/i)*(min(b,d)/i);
        printf("Case %d: %lld\n",ca,ans1-ans2/2);
    }
    return 0;
}
