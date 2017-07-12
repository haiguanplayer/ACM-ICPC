#include <cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6+5;
int a[N],b[N*3],maxn[N],minn[N];
ll ans;
int read() 
{
    char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    int x=ch-'0';
    for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
void solve(int l,int r)
{
	int mid = (l+r)/2;
	maxn[mid] = minn[mid] = a[mid];
	for(int i = mid-1;i >= l;i--)
	{
		maxn[i] = max(a[i],maxn[i+1]);
		minn[i] = min(a[i],minn[i+1]);
	}
	maxn[mid+1] = minn[mid+1] = a[mid+1];
	for(int i = mid+2;i <= r;i++)
	{
		maxn[i] = max(a[i],maxn[i-1]);
		minn[i] = min(a[i],minn[i-1]);
	}

	for(int i = mid;i >= l;i--)
	{
		int j = maxn[i] - minn[i] + i;
		if(j > mid && j <= r && maxn[i] > maxn[j] && minn[i] < minn[j])
			ans++;
	}
	for(int j = mid+1;j <= r;j++)
	{
		int i = -(maxn[j]-minn[j]-j);
		if(i >= l && i <= mid && maxn[j] > maxn[i] && minn[i] > minn[j])
			ans++;
	}
	int left = mid+1,right = mid;
	for(int i = mid;i >= l;i--)
	{
		while(right < r && maxn[right+1] < maxn[i])
			right++,b[minn[right]+right+N]++;
		while(left <= right && minn[left] > minn[i])
			b[minn[left]+left+N]--,left++;
		ans += b[maxn[i]+i+N];
	}
	while(left <= right)
		b[minn[left]+left+N]--,left++;
	left = mid+1,right = mid;
	for(int j = mid+1;j <= r;j++)
	{
		while(left > l && maxn[left-1] < maxn[j])
			left--,b[minn[left]-left+N]++;
		while(left <= right && minn[right] > minn[j])
			b[minn[right]-right+N]--,right--;
		ans += b[maxn[j]-j+N];
	}
	while(left <= right)
		b[minn[right]-right+N]--,right--;
	if(l == r)
		return;
	solve(l,mid);
	solve(mid+1,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		a[i] = read();

	ans = n;
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}