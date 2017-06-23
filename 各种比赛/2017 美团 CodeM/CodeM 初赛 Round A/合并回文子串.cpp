#include<bits/stdc++.h>
using namespace std;

const int N = 55;
char a[N],b[N];
bool f[N][N][N][N];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		scanf("%s",a+1);
		scanf("%s",b+1);
		int n = strlen(a+1);
		int m = strlen(b+1);
		memset(f,false,sizeof(f));
		int maxn = 0;
		for(int len1 = 0;len1 <= n;len1++)
			for(int len2 = 0;len2 <= m;len2++)
				for(int i = 1,j = len1;j <= n;i++,j++)
					for(int k = 1,l = len2;l <= m;k++,l++)
					{
						if(len1+len2 <= 1)//±Ø¶¨·ûºÏ
							f[i][j][k][l] = true;
						else
						{
							if(len1 > 1 && a[i] == a[j])
								f[i][j][k][l] |= f[i+1][j-1][k][l];
							if(len2 > 1 && b[k] == b[l])
								f[i][j][k][l] |= f[i][j][k+1][l-1];
							if(len1 && len2 && a[i] == b[l])
								f[i][j][k][l] |= f[i+1][j][k][l-1];
							if(len1 && len2 && b[k] == a[j])
								f[i][j][k][l] |= f[i][j-1][k+1][l];
						}
						if(f[i][j][k][l])
							maxn = max(maxn,len1+len2);
					}
		cout << maxn << endl;

	}
	return 0;
}
