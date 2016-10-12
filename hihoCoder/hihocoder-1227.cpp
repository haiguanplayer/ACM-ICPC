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
            int R = ceil(d[n-1]);//����0~n-1��n����
            R = R == d[n-1] ? R+1 : R;
            if(m != n && R >= d[n])//��n+1����ѹ�磬����������m��=n��Խ��
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
