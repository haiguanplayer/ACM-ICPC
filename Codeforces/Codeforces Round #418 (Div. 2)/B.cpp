#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N],b[N],num[N];
int n;
bool judge(int a[N],int b[N])
{
    int res = 0;
    for(int i = 1;i <= n;i++)
        if(a[i] != b[i])
            res++;
    return res == 1;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]),num[a[i]]++;
	for(int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	int cnt;
	for(int i = 1;i <= n;i++)
		if(!num[i])
			cnt = i;
	for(int i = 1;i <= n;i++)
	{
		if(num[a[i]] == 2)
		{
			int temp = a[i];
			a[i] = cnt;
			if(judge(a,b))
				break;
			else
				a[i] = temp;
		}
	}
	for(int i = 1;i <= n;i++)
		printf("%d%s",a[i],i == n ?"\n":" ");
	return 0;
}
