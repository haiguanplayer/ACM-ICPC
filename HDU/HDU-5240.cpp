#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct node
{
    int r,e,l;
    bool operator < (const node & p)const
    {
        return e < p.e;
    }
}p[N];
int main()
{
    int t,n;
    cin>>t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        bool flag = true;
        for(int i = 0;i < n;i++)
            scanf("%d%d%d",&p[i].r,&p[i].e,&p[i].l);
        printf("Case #\%d: ",ca);
        sort(p,p+n);
        int sum = 0,endd = 0;
        for(int i = 0;i < n;i++)
        {
            sum += p[i].e-endd-p[i].r;//这次开始考试时间减去上次考试结束时间，再减去需要复习的时间
            if(sum < 0 || endd > p[i].e)
            {
                flag = false;
                break;
            }
            endd = p[i].e + p[i].l;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
