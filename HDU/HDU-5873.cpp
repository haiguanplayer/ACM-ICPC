#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20005];
int main()
{
    int m,b;
    while(~scanf("%d",&m))
    {
        while(m--)
        {
            scanf("%d",&b);
            int sum = 0,ans = 0;
            bool flag = false;
            for(int i = 1;i <= b;i++)
            {
                scanf("%d",&a[i]),sum += a[i];
                if(a[i] % 2)
                    ans++;
                if(a[i] > 2*(b-1))
                    flag = true;
            }
            if(flag || ans % 2 || sum != b*b - b)
                printf("F\n");
            else
                printf("T\n");
        }
    }
    return 0;
}
