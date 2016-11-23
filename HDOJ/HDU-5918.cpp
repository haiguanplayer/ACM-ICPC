///给出两个数组a,b。b数组匹配a数组，不是连续匹配，而是相隔p位置匹配，求a数组中能匹配出多少次b数组。
//baoli
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1000005;
int a[N],b[N];

int main()
{
    int t,n,m,p;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= m;i++)
            scanf("%d",&b[i]);
        printf("Case #%d: ",ca);
        int sum = 0;
        for(int i = 1;i <= n && i+(m-1)*p <= n;i++)
        {
            int j = 0,r = i;
            while(a[r] == b[j+1])
            {
                j++;
                r = i + j*p;
                if(j >= m)
                {
                    sum++;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

//KMP
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int Next[2000100];
int a[2000100],b[2000100],c[2000100];
void Getfail(int m)
{
    int j, k;
    j = 0; k = -1; Next[0] = -1;
    while(j < m)
        if(k == -1 || b[j] == b[k])
            Next[++j] = ++k;
        else
            k = Next[k];

}
int KMP(int n,int m)
{
    int i = 0,j = 0,ans = 0;
    while(i < n)
    {
        if(j == -1 || c[i] == b[j])
        {
            i++,j++;
            if(j == m)
            {
                j = Next[j];
                ans++;
            }
        }
        else
            j = Next[j];
    }
    return ans;
}
int main()
{
    int t,n,m,p;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        for(int i = 0;i < m;i++)
            scanf("%d",&b[i]);
        printf("Case #%d: ",ca);
        int sum = 0;
        Getfail(m);
        for(int i = 0;i < p;i++)
        {
            int num = 0;
            for(int j = i;j < n && i+(m-1)*p < n;j += p)
                c[num++] = a[j];
            sum += KMP(num,m);
        }
        printf("%d\n",sum);
    }
    return 0;
}
