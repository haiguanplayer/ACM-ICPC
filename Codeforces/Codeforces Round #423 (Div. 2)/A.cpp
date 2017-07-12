#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int x[N];
int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	int ans = 0,c = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&x[i]);
		if(x[i] == 1)
		{
			if(a > 0)
				a--;
			else if(b > 0)
				c++,b--;
			else if(c > 0)
				c--;
			else
				ans++;
		}
		else if(x[i] == 2)
		{
			if(b > 0)
				b--;
			else
				ans += 2;
		}
	}
	cout << ans << endl;
	return 0;
}