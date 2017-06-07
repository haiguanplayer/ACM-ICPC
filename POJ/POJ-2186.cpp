/*
Popular Cows
给定一个有向图，求有多少个顶点是由任何顶点出发都可达的。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 11005;

int n,m,e;
int low[N],dfn[N],stack[N],instack[N],belong[N],out[N],head[N];
int index,cnt,top;

struct Edge
{
    int to;
    int next;
}edge[N*5];

void addEdge(int u, int v)
{
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}


void Init()
{
    cnt = 1;
    e = 0;
    index = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(head, -1, sizeof(head));
    memset(instack, 0, sizeof(instack));
    memset(belong, 0, sizeof(-1));
    memset(out, 0, sizeof(out));
}

void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = cnt++;
    instack[u] = 1;
    stack[++top] = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(dfn[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u] == dfn[u])
    {
        index++;
        do
        {
            v = stack[top--];
            instack[v] = 0;
            belong[v] = index;
        }
        while(top != 0 && v != u);
    }
}


int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        Init();
        int u,v;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&u,&v);
            addEdge(u, v);
        }
        int num = 0, ans = 0,tmp;
        for(int i = 1; i <= n; i++)
        {
            if(dfn[i] == -1)
                tarjan(i);
        }

        for(int i = 1; i <= n; i++)
        {
            for(int v = head[i]; v != -1; v = edge[v].next)
            {
                if(belong[i] != belong[edge[v].to])
                {
                    out[belong[i]]++;
                }

            }
        }

        for(int i = 1; i <= index; i++)
        {
            if(!out[i])
            {
                num++;
                tmp = i;
            }
        }

        if(num == 1)
        {
            for(int i = 1; i <= n; i++)
            {
                if(belong[i] == tmp)
                    ans++;
            }
            printf("%d\n", ans);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
