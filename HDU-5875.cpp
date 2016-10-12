#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn =100005;
int data[maxn];
int flag[maxn];

priority_queue<int >q;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int i,j;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&data[i]);


        q.push(1);
        for(i=2;i<=n;i++)
        {
            while(!q.empty()&&data[i]<data[q.top()])
            {
                flag[q.top()]=i;
                q.pop();
            }
            q.push(i);
        }
        while(!q.empty())
        {
            flag[q.top()]=-1;
            q.pop();
        }

        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int fn=l;
            int ans=data[l];
            while(fn<=r)
            {
                int wtf=flag[fn];
                if(wtf==-1)
                    break;
                else if(wtf>r)
                    break;
                else if(wtf<=r)
                {
                    ans=ans%data[wtf];
                    fn=wtf;
                }
                if(ans==1)
                    break;
            }
             printf("%d\n",ans);
        }

    }
    return 0;
}
