#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10005;

int n,m;
vector<int> G[N];
int low[N],dfn[N],stack[N],instack[N],belong[N],in[N],out[N];
int head,indexx,cnt;

void Init()
{
    for(int i = 0;i < N;i++)
    {
        G[i].clear();
        dfn[i] = -1;
        low[i] = instack[i] = in[i] = out[i] = belong[i] = 0;
    }
    indexx = cnt = 1;
    head = 0;
}

void tarjan(int u)
{
    low[u] = dfn[u] = indexx++;
    stack[++head] = u;
    instack[u] = 1;
    for(int i = 0;i < G[u].size();i++)
    {
        if(!G[u][i])
            continue;
        int v = G[u][i];
        if(dfn[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
        {
            low[u] = min(low[u],dfn[v]);
        }
    }

    if(low[u] == dfn[u])
    {
        int temp;
        while(1)
        {
            temp = stack[head--];
            belong[temp] = cnt;
            instack[temp] = 0;
            if(temp == u)
                break;
        }
        cnt++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Init();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        for(int i = 1;i <= n;i++)
            if(dfn[i] == -1)
                tarjan(i);
        for(int i = 1;i <= n;i++)
            for(int j = 0;j < G[i].size();j++)
            {
                int v = G[i][j];
                if(G[i][j] && belong[i] != belong[v])
                {
                    out[belong[i]]++;
                    in[belong[v]]++;
                }
            }


        int t1 = 0,t2 = 0;
        for(int i = 1;i < cnt;i++)
        {
            if(in[i] == 0)
                t1++;
            if(out[i] == 0)
                t2++;
        }
        if(cnt == 2)
            printf("0\n");
        else
            printf("%d\n",max(t1,t2));
    }
    return 0;
}
