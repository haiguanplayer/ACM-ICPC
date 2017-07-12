#include<bits/stdc++.h>
using namespace std;

const int N = 3*1e6+5;
char str[N],s[N];
int f[N];
int getf(int x)
{
	return f[x] == x ? x : f[x] = getf(f[x]);
}
int main()
{
	for(int i = 0;i < N;i++)
		f[i] = i;
	int n,k,pos;
	cin >> n;
	int end = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%s %d",s,&k);
		int len = strlen(s);
		while(k--)
		{
			scanf("%d",&pos);
			pos--;
			end = max(end,pos+len);
			int p = pos;
			while((p = getf(p)) < pos+len)
			{
				str[p] = s[p-pos];
				f[p] = p + 1;
			}
		}
	}

	for(int i = 0;i < end;i++)
		printf("%c",str[i] ? str[i] :'a');
	printf("\n");
	return 0;
}