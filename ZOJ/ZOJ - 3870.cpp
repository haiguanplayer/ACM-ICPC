#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5+5;
int a[N],num[N];

void Cal(int x)
{
    int l = 31;
    while(l-- >= 0)
    {
        if(x & (1 << l))
        {
            num[l]++;
            return;
        }
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            Cal(a[i]);
        }

        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int l = 31;
            while(l-- >= 0)//
            {
                if(a[i] & (1 << l))//找到a[i]的第一位即最高位
                    break;
            }

            while(l-- >= 0)//找到a[i]的0位，这时候与最高位在此处的数异或肯定大于a[i]
            {
                if((a[i] & (1 << l)) == 0)
                    ans += num[l];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
