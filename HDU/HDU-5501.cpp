//similar with SD province K
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct ti
{
	int a,d,c;
	double bi;
	bool friend operator<(ti a,ti b)
	{
		return a.bi<b.bi;
	}
}a[2200];
int n,t;
int f[5500];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&t);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].a,&a[i].d,&a[i].c);
        for(int i=1;i<=n;i++)
            a[i].bi=(double)a[i].d/(double)a[i].c;
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--)
        {
            for(int j=t;j>=a[i].c;j--)
            {
                f[j]=max(f[j],f[j-a[i].c]+a[i].a-a[i].d*j);
            }
        }
        int ans=0;
        for(int i=0;i<=t;i++)
            ans=max(ans,f[i]);
        printf("%d\n",ans);
    }

	return 0;
}
