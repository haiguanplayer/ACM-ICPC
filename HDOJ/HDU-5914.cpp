#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",ca);
        if(n <= 3)
            printf("0\n");
        else
        {
            int a = 2,b = 3,sum = 0;
            for(int i = 4;i <= n;i++)
            {
                if(a+b > i)
                    sum++;
                else
                    a = b,b = i;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
