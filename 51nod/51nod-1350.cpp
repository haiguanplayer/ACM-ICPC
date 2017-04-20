#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

ll f[105] = {0,1,1},w[1005] = {0,1,1};
void Init()
{
    for(int i = 3;i <= 84;i++)
    {
        f[i] = f[i-1] + f[i-2];
        w[i] = w[i-1] + w[i-2] + f[i-2];
    }
}
ll p(int i,ll j)
{
    if(j == f[i])
        return w[i];
    if(j <= f[i-1])//�Ҷ�λ��
        return p(i-1,j);
    //�е������
    return p(i-1,f[i-1]) + p(i-2,j - f[i-1]) + j - f[i-1];
}
int main()
{
    Init();
    int t;
    cin >> t;
    ll n;
    while(t--)
    {
        scanf("%lld",&n);
        int id = 0;
        ll sum = 0,ans = 0;
        while(sum + f[id+1] < n)//�����Ӧ�ε�λ��
            sum += f[++id];
        for(int i = 1;i <= id;i++)
            ans += w[i];
        //Ȼ�������һ��
        ans += p(id+1,n-sum);
        printf("%lld\n",ans);
    }
    return 0;
}
