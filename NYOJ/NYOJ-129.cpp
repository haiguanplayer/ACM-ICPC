#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 10005;
int f[N],vis[N],n;
bool flag;
void Init()
{
    for(int i = 1;i <= N;i++)
    {
        vis[i] = 0;
        f[i] = i;
    }
}
int getf(int t)
{
    if(f[t] == t)
        return t;
    return f[t] = getf(f[t]);
}
void merge(int v,int u)
{
    int t1,t2;
    t1 = getf(v);
    t2 = getf(u);
    if(t1!=t2)
    {
        f[t2] = t1;//靠左原则
    }
    if(t2!=u||t1==t2)
        flag=0;//保证u不在另一个树中，入度不大于1，在一个集合中，再连接就成回路，不满足树
}
int main()
{
    int t=0;
    int x,y;
    Init();
    while(~scanf("%d%d",&x,&y)&&(x>=0||y>=0))
    {
        t++;
        if(!x || !y)
        {
            cout<<"Case "<<t;
            cout<<" is a tree."<<endl;
            continue;
        }
        flag = true;
        merge(x,y);
        vis[x]=vis[y]=1;//此数组用来标记是否有这个点
        while(scanf("%d%d",&x,&y)&&(x||y))
        {
            merge(x,y);
            vis[x] = vis[y] = 1;
        }
        int sum=0;
        for(int i=1;i<=N;i++)//貌似不会有超时影响
        {
            if(vis[i]&&f[i] == i)
                sum++;
        }
        if(sum > 1)
            flag = false;

        cout<<"Case "<<t;
        if(flag)
            cout<<" is a tree."<<endl;
        else
            cout<<" is not a tree."<<endl;
        Init();
    }
}

