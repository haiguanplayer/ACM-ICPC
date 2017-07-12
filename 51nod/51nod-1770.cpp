#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t,a,b,d,n;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> d >> n;
		int ans = 0;
		if(a*b % 10 == d)
			ans++;
		if(n == 1 && a*b/10 == d && a*b >= 10)
			ans++;
		if(n >= 2)
		{
			if((a*b+a*b/10) % 10 == d)
				ans++;
			if((a*b + (a*b+a*b/10)/10) % 10 == d)
				ans += n-2;
			if((a*b + (a*b+a*b/10)/10) >= 10 && (a*b + (a*b+a*b/10)/10) / 10 == d)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
