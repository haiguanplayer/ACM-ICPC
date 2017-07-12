#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int ans = (n-1)/k*2 + min(2,(n-1)%k);
	cout << ans << endl;
	for(int i = n;i > k;i--)
		printf("%d %d\n",i,i-k);
	for(int i = k;i > 1;i--)
		printf("%d 1\n",i);
	return 0;
}