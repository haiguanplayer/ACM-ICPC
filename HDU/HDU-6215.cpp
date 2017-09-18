#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N],last[N],nxt[N],vis[N],que[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        int ans = n,top = 0;
        a[0] = 0;
        nxt[0] = 1;last[n+1] = n;
        for(int i = 1;i <= n;i++)
        {
            nxt[i] = i+1;
            last[i] = i-1;
            scanf("%d",&a[i]);
            que[top++] = i;
        }
        int flag = 1,head,now;
        while(flag)
        {
            flag = head = now = 0;
            while(now < top)
            {
                int i = que[now],num = 0;
                while(nxt[i] <= n)
                {
                    if(a[i] > a[nxt[i]])
                        num++,i = nxt[i],flag = 1;
                    else
                        break;
                }

                if(num)
                    ans -= num+1;
                if(num)
                {
                    int cur = que[now];
                    nxt[last[cur]] = nxt[i];
                    last[nxt[i]] = last[cur];
                    que[head++] = last[cur];
                }
                while(que[now] <= i && now < top)
                    now++;
            }
            top = head;
        }
        printf("%d\n",ans);
        int p = 0;
        while(p <= n)
        {
            if(p)
                printf("%d ",a[p]);
            p = nxt[p];
        }
        printf("\n");
    }
}
