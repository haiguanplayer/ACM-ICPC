#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[100005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lld",&a[i]);
            while(a[i] > 0)
            {
                if(a[i] % 256 == 97)
                    sum++;
                a[i] /= 256;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
