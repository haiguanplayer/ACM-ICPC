#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N*2],b[N*2];
int main()
{
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i = 0;i < x*2;i+=2)
            scanf("%d%d",&a[i],&a[i+1]);
        for(int i = 0;i < y*2;i+=2)
            scanf("%d%d",&b[i],&b[i+1]);

        int res = 0,i = 0, j = 0,day;
        while(i < x*2 && j < y*2)
        {
            if(a[i] < b[j])//a的开始早于b
            {
                if(a[i+1] < b[j+1])//a的结束早于b
                {
                    day = a[i+1] - b[j] + 1;
                    i += 2;
                    if(day >= m)
                        res += day - m + 1;
                }
                else
                {
                    day = b[j+1] - b[j] + 1;
                    j += 2;
                    if(day >= m)
                        res += day - m + 1;
                }
            }
            else
            {
                if(a[i+1] < b[j+1])
                {
                    day = a[i+1] - a[i] + 1;
                    i += 2;
                    if(day >= m)
                        res += day - m + 1;
                }
                else
                {
                    day = b[j+1] - a[i] + 1;
                    j += 2;
                    if(day >= m)
                        res += day - m + 1;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
