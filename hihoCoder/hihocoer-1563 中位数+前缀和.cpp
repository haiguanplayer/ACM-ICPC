#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, m, vis[3*N];
long long pre[3*N], dig[3*N];
bool jug(int lft, int rgt)
{
	if(dig[rgt] - dig[lft-1] >= m)	return true;
	return false;
}
long long calc(int idx)
{
	int l = 0, r = n, mid, ans = 0;
	while(l <= r)
	{
		mid = (l+r) >> 1;
		if(jug(idx-mid, idx+mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}
int main()
{
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &vis[i]);
			vis[i+n] = vis[i];
			vis[i+n*2] = vis[i];
			cnt += (vis[i] == 0 ? 1 : 0);
		}
		if(cnt < m)	{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=3*n;i++)
		{
			if(vis[i] == 0) {
				dig[i] = dig[i-1] + 1;
				pre[i] = pre[i-1] + i;
			} else {
				dig[i] = dig[i-1];
				pre[i] = pre[i-1];
			}
		}
		long long mn = 1ll<<60;
		long long cal = 0;
		for(int i=n+1;i<=n+n;i++)
		{
			int seg = calc(i);
			cal = i*(dig[i]-dig[i-seg-1]) - (pre[i] - pre[i-seg-1]) + (pre[i+seg]-pre[i]) - i*(dig[i+seg]-dig[i]);
			if(dig[i+seg] - dig[i-seg-1] == m+1)	cal -= seg;
			mn = min(mn, cal);
		}
		printf("%lld\n", mn);
	}
}
