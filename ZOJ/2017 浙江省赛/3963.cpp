#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N],deg[N];
vector<int> G[N];
struct node
{
    int first,second;
    bool operator < (const node & p)const
    {
        if(a[second] == a[p.second])
            return second < p.second;
        return a[second] < a[p.second];
    }
}p;
set<node> s;
set<node>::iterator it;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        //memset(deg,0,sizeof(deg));
        s.clear();
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            deg[i] = 0;
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            p.second = i;
            it = s.upper_bound(p);
            if(it == s.begin())//Ã»ÕÒµ½
            {
                G[cnt].push_back(i);
                p.first = cnt,p.second = i;
                s.insert(p);
                cnt++;
            }
            else
            {
                it--;
                p = *it;
                deg[p.second]++;
                if(deg[p.second] == 2)
                    s.erase(it);
                p.second = i;
                s.insert(p);
                G[p.first].push_back(i);
            }
        }

        printf("%d\n",cnt);
        for(int i = 0;i < cnt;i++)
        {
            printf("%d",G[i].size());
            for(int j = 0;j < G[i].size();j++)
                printf(" %d",G[i][j]);
            printf("\n");
            G[i].clear();//nice
        }
    }
    return 0;
}
