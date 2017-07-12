#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300005;
int n,m,a[N];
ll p[N];
int main()
{
	ll all = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i < n;i++)
	{
		int l = a[i-1],r = a[i];
		if(l > r) r += m;
		all += r-l;
		if(r-l > 1)
		{
			p[l+2]++;
			p[r+1] -= (r-(l+2)+1) + 1;
			p[r+2] += (r-(l+2)+1);
		}
	}

	for(int i = 1;i <= m*2;i++) p[i] += p[i-1];
	for(int i = 1;i <= m*2;i++) p[i] += p[i-1];
	ll ans = -1;
	for(int i = 1;i <= m;i++)
		ans = max(ans,p[i]+p[i+m]);
	cout << all-ans << endl;
	return 0;
}