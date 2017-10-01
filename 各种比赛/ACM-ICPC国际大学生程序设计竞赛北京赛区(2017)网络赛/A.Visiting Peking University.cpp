#include<bits/stdc++.h>
using namespace std;

int p[105],vis[1005];
int main()
{
    int n,m,q,x;
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < n;i++)
            scanf("%d",&p[i]);
        scanf("%d",&q);
        while(q--)
            scanf("%d",&x),vis[x] = 1;
        int pos1,pos2,value = 2000;
        for(int i = 0;i < n;i++)
        {
            int jj,cnt = 1,minn = 1000;
            if(!vis[i])
            for(int j = i+1;j < n;j++)
            {
                if(!vis[j])
                {
                    cnt++;
                    if(minn > p[j])
                    {
                        minn = p[j];
                        jj = j;
                    }
                }
                if(cnt == m)
                {
                    if(value > p[i]+minn)
                    {
                        value = p[i]+minn;
                        pos1 = i;
                        pos2 = jj;
                    }
                    break;
                }
            }
        }
        cout<<pos1<<" "<<pos2<<"\n";
    }
    return 0;
}
