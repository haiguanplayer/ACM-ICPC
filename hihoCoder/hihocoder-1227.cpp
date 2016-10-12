#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
pair<double,double>p[N];
double d[N];
int main()
{
    int t,m,n;
    cin >> t;
    while(t--)
    {
        int ans = N;
        cin >> m >> n;
        for(int i = 0;i < m;i++)
            scanf("%lf%lf",&p[i].first,&p[i].second);


        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < m;j++)
                d[j] = sqrt((p[i].first - p[j].first)*(p[i].first - p[j].first)+(p[i].second - p[j].second)*(p[i].second - p[j].second));

            sort(d,d+m);
            int R = ceil(d[n-1]);//覆盖0~n-1共n个点
            R = R == d[n-1] ? R+1 : R;
            if(m != n && R >= d[n])//第n+1个点压界，不符合条件m！=n否越界
                continue;

            if(R < ans)
                ans = R;
        }

        if(ans == N)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
