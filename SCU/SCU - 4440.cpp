#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        long long sum = 0;
        int len;
        for(int i = 1;i <= n && i*2 < k/2*2;i++)
        {
            len = k/2 - i;
            len = min(len,m);
            //cout<<len << " "<<m<<endl;
            //cout<<(n-i+1)*(2*m - len + 1)*len/2<<endl;
            sum += 1ll*(n-i+1)*(2*m - len + 1)*len/2;
        }
        /*
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if((i+j)*2 > k)
                    break;
                sum += 1ll*(n-i+1)*(m-j+1);
            }
        }*/
        printf("%lld\n",sum);
    }
    return 0;
}
//15625 62500 62500 0000
