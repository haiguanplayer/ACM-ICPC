//by Guo Wei
/*
输入图的邻接矩阵，求最小生成树的总权值
(多组数据）
 时间复杂度：O(ElogV) 或 O(VlogV+E)(斐波那契堆）
适用于密集图
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int  INFINITE = 1 << 30;
struct Edge
{
    int v; //边端点，另一端点已知
    int w; //边权值，也用来表示v到在建最小生成树的距离
    Edge(int v_ = 0, int w_ = INFINITE):v(v_),w(w_) { }
    bool operator <(const Edge & e) const
    {
        return w > e.w;  //在队列里，边权值越小越优先
    }
};
vector< vector <Edge> > G(110); //图的邻接表
int HeapPrim(const vector<vector<Edge> > & G, int n)
//G是邻接表,n是顶点数目，返回值是最小生成树权值和
{
    int i,j,k;
    Edge xDist(0,0);
    priority_queue<Edge> pq; //存放顶点及其到在建生成树的距离
    vector<int> vDist(n); //各顶点到已经建好的那部分树的距离
    vector<int> vUsed(n);//标记顶点是否已经被加入最小生成树
    int nDoneNum = 0; //已经被加入最小生成树的顶点数目
    for( i = 0;i < n;i ++ )
    {
        vUsed[i] = 0;
        vDist[i] = INFINITE;
    }
    nDoneNum = 0;
    int nTotalW = 0; //最小生成树总权值
    pq.push(Edge(0,0)); //开始只有顶点0，它到最小生成树距离0
    while(nDoneNum < n && !pq.empty())
    {
        do {//每次从队列里面拿离在建生成树最近的点
            xDist = pq.top();
            pq.pop();
        }while( vUsed[xDist.v] == 1 && ! pq.empty());
        if( vUsed[xDist.v] == 0 )
        {
            nTotalW += xDist.w; vUsed[xDist.v] = 1; nDoneNum ++;
            for( i = 0;i < G[xDist.v].size();i ++ )
            {//更新新加入点的邻点
                int k = G[xDist.v][i].v;
                if( vUsed[k] == 0)
                {
                    int w = G[xDist.v][i].w ;
                    if( vDist[k] > w )
                    {
                        vDist[k] = w;
                        pq.push(Edge(k,w));
                    }
                }
            }
        }
    }
    if( nDoneNum < n )
        return -1; //图不连通
    return nTotalW;
}
int main()
{
    int N;
    while(cin >> N)
    {
        for( int i = 0;i < N; ++i)
            G[i].clear();
        for( int i = 0; i < N; ++i)
        for( int j = 0; j < N; ++j)
        {
            int w;
            cin >> w;
            G[i].push_back(Edge(j,w));
        }
        cout << HeapPrim(G,N) << endl;
    }
}
