#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[1005];
int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&x);
            num[x]++;
        }
        int maxn = 0,cnt;
        for(int i = 1;i <= 1000;i++)
        {
            if(num[i] > maxn)
            {
                cnt = i;
                maxn = num[i];
            }
        }
        int p = 0;
        for(int i = 1;i <= 1000;i++)
        {
            if(num[i] == maxn)
                p++;
        }
        if(p == 1)
            printf("%d\n",cnt);
        else
            printf("Nobody\n");
    }
}
