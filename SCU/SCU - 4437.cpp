#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+5;
int a[N],b[N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        int k = 1;
        long long ans = 0;
        for(int i = 1;i <= 9;i++)
        {
            k *= 10;
            for(int j = 1;j <= n;j++)
                b[j] = a[j]%k;

            sort(b+1,b+1+n);
            for(int j = 1;j <= n;j++)
            {
                int pos = lower_bound(b+j+1,b+1+n,k-b[j])-b;
                //cout<<n-pos<<endl;
                ans += n-pos+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
