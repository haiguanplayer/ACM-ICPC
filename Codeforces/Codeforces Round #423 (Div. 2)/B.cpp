#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char str[N][N];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		scanf("%s",str[i]);
	int sum = 0,max_i = 0,max_j = 0,min_i = n,min_j = m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if(str[i][j] == 'B')
			{
				sum++;
				max_i = max(max_i,i);
				max_j = max(max_j,j);
				min_i = min(min_i,i);
				min_j = min(min_j,j);
			}
	int line = max((max_i-min_i+1),(max_j-min_j+1));
	if(sum == 0)
		cout << 1 << endl;
	else if(line <= min(n,m))
		cout << line*line-sum << endl;
	else
		cout << -1 << endl;
	return 0;
}