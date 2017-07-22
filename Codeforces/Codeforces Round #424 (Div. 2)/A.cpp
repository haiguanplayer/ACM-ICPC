#include<cstdio>
#include<iostream>
using namespace std;

const int N = 105;
int a[N];
int n,maxn = 1;

bool check()
{
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == maxn)
		{
			for(int j = i-1;j >= 1;j--)
				if(a[j] >= a[j+1])
					return false;
			while(a[i] == maxn && i <= n)
				i++;
			for(int j = i;j <= n;j++)
				if(a[j-1] <= a[j] || a[j] >= maxn)
					return false;
			break;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i],maxn = max(a[i],maxn);

	if(check())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
