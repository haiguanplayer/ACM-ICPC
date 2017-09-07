#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 300005;
const int hn = 19;

char s[N];
int n,m,fa[35];
ull Hash[N],h[N][26],p[N]={1};

int getf(int x)
{
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}
void init()
{
    scanf("%s",s+1);
	n = strlen(s+1);
	for(int i = 1;i <= n;++i)
        p[i] = p[i-1]*hn;
	for(int i = 1;i <= n;++i)
    {
		Hash[i] = Hash[i-1]*hn + s[i]-'a';
		for(int j = 0;j < 26;++j)
            h[i][j] = h[i-1][j]*hn;
		h[i][s[i]-'a']++;
	}
}
bool check(int l1,int r1,int l2,int r2)
{
	int len = r1-l1+1;
	ull v1=Hash[r1]-Hash[l1-1]*p[len],v2=Hash[r2]-Hash[l2-1]*p[len];
	for(int i = 0;i < 26;++i)
    {
		int f = getf(i);
		if(i != f)
		{
			v1 -= i*h[r1][i]-i*h[l1-1][i]*p[len];
			v2 -= i*h[r2][i]-i*h[l2-1][i]*p[len];
			v1 += f*h[r1][i]-f*h[l1-1][i]*p[len];
			v2 += f*h[r2][i]-f*h[l2-1][i]*p[len];
		}
	}
	return v1 == v2;
}

int main()
{
	init();
	scanf("%d",&m);
	char ch[5];
	int k,l1,l2,r1,r2;
	while(m--)
    {
        scanf("%d%d%d%d%d",&k,&l1,&r1,&l2,&r2);
		if(r1-l1 != r2-l2)
			printf("NO\n");
        else
        {
			int len=r1-l1+1;
			for(int i=0;i<26;++i)
                fa[i] = i;
			for(int i=1;i<=k;++i)
            {
				scanf("%s",ch);
				int f1=getf(ch[0]-'a'),f2=getf(ch[1]-'a');
				if(f1!=f2)
                    fa[f1]=f2;
			}
			if(check(l1,r1,l2,r2))
				printf("YES\n");
			else
			{
				int l=0,r=len,mid;
				while (l<r)
				{
					mid=l+r+1>>1;
					if(check(l1,l1+mid-1,l2,l2+mid-1))
                        l=mid;
                    else
                        r=mid-1;
				}
				++l;
				if(l==len)
					printf("YES\n");
				else
				{
					if(check(l1+l,r1,l2+l,r2))
                        printf("YES\n");
                    else
                        printf("NO\n");
				}
			}
		}
	}
	return 0;
}

