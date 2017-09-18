#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define ll long long
const ll maxm = 10005;
const ll INF = 1e18 + 7;
struct node
{
	ll u, v, flow, cost, next;
}edge[maxm * 10];
map<string, ll>p;
ll cnt, s, t, n, m, sum, FLOW;
ll ans;
ll head[maxm * 10], dis[maxm * 10], pre[maxm * 10];
char a[maxm], b[maxm];
void init()
{
	p.clear();
	cnt = 0, s = 0, t = n * 5 + 1, sum = 0, FLOW = 0,ans = 0;
	memset(head, -1, sizeof(head));
}
void add(ll u, ll v, ll flow, ll cost)
{
	edge[cnt].u = u, edge[cnt].v = v;
	edge[cnt].flow = flow, edge[cnt].cost = cost;
	edge[cnt].next = head[u], head[u] = cnt++;
	edge[cnt].u = v, edge[cnt].v = u;
	edge[cnt].flow = 0, edge[cnt].cost = -cost;
	edge[cnt].next = head[v], head[v] = cnt++;
}
bool spfa()
{
	queue<ll>q;
    for (ll i = 0;i <= t;i++) dis[i] = INF;
    memset(pre, -1, sizeof(pre));
    dis[s] = 0, q.push(s);
    ll rev = 0;
    while (!q.empty())
    {
        ll u = q.front();q.pop();
        for (ll i = head[u];i != -1;i = edge[i].next)
        {
            ll v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].cost&&edge[i].flow)
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i, q.push(v);
            }
        }
    }
    if (dis[t] == INF) return 0;
    return 1;
}
void MCMF()
{
    ll minflow;
	while (spfa())
	{
		minflow = INF;
		for (ll i = pre[t];i != -1;i = pre[edge[i].u])
			minflow = min(minflow, edge[i].flow);
		for (ll i = pre[t];i != -1;i = pre[edge[i].u])
			edge[i].flow -= minflow, edge[i ^ 1].flow += minflow;
		ans += dis[t] * minflow;
		FLOW += minflow;
	}
}
int main()
{
	ll i, j, k, T, c;
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &n);
		init();
		ll nn = n * 2;
		for (i = 1;i <= n;i++)
		{
			scanf("%s%s%lld", a, b, &c);
			if (p[a] == 0)
			{
				p[a] = ++sum, k = 1;
				if (strcmp(a, "Shanghai") == 0) k = 2;
				add(p[a], p[a] + nn, k, 0);
			}
			if (p[b] == 0)
			{
				p[b] = ++sum, k = 1;
				if (strcmp(b, "Shanghai") == 0) k = 2;
				add(p[b], p[b] + nn, k, 0);
			}
			ll u = p[a], v = p[b];
			add(u + nn, v, INF, c);
			add(v + nn, u, INF, c);
		}
		ll u = p["Dalian"];
		add(s, u, 1, 0);
		u = p["Xian"];
		add(s, u, 1, 0);
		u = p["Shanghai"];
		add(u + nn, t, 2, 0);
		MCMF();
		if (FLOW == 2) printf("%lld\n", ans);
		else printf("-1\n");
	}
	return 0;
}
