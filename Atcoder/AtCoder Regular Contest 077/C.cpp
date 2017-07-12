#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);

	if(n&1)
	{
		int num = n;
		while(num > 1)
		{
			printf("%d ",a[num]);
			num -= 2;
		}
		printf("%d ",a[1]);
		num = 2;
		while(num < n)
		{
			printf("%d ",a[num]);
			num += 2;
		}
	}
	else
	{
		int num = n;
		while(num > 1)
		{
			printf("%d ",a[num]);
			num -= 2;
		}
		printf("%d ",a[1]);
		num = 3;
		while(num < n)
		{
			printf("%d ",a[num]);
			num += 2;
		}
	}
	printf("\n");
	return 0;
}
/*
1
1

1 2
2 1

2 1 3
3 1 2

3 1 2 4
4 2 1 3

4 2 1 3 5
5 3 1 2 4

5 3 1 2 4 6
6 4 2 1 3 5

6 4 2 1 3 5 7
7 5 3 1 2 4 6
*/