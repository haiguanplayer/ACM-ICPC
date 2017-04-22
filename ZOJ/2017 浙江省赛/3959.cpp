#include<bits/stdc++.h>

using namespace std;

int a[105];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);

        int minn = 1000,maxn = -1000,num = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] == 1)
                num++;
            minn = min(minn,a[i]);
            maxn = max(maxn,a[i]);
        }
        if(n < 10 || n > 13)
        {
            printf("No\n");
            continue;
        }
        if(num < 2 ||  minn != 1)
        {
            printf("No\n");
            continue;
        }
        sort(a,a+n);
        bool flag = false;
        for(int i = 0;i < n-1;i++)
        {
            if(abs(a[i]-a[i+1]) > 2)
            {
                if(a[i] == maxn || a[i+1] == maxn)
                    continue;
                flag = true;
                break;;
            }
        }
        if(!flag)
            printf("Yes\n");
            else
                printf("No\n");
    }
}
