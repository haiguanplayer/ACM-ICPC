#include<bits/stdc++.h>
using namespace std;


const int MAXS = 100005;
const int MAXT = 20;
int len,tr[MAXS];
char s[MAXS], t[MAXT];

int lowbit(int x)
{
	return ((x-1)^x)&x;
}

void add(int p,int x)
{
	while (p<=len)
	{
		tr[p]+=x;
		p+=lowbit(p);
	}
}

int sum(int p)
{
	int s=0;
	while (p>0)
	{
		s+=tr[p];
		p-=lowbit(p);
	}
	return s;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,ls,lt;
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        ls = strlen(s);
        lt = strlen(t);
        len = ls - lt + 1;
        for(int i = 1;i <= len;i++)
            tr[i] = 0;

        for(int i = 1;i <= len;i++)
        {
            for(int j = 0; j < lt; j++)
            {
                if (s[i + j - 1] != t[j])
                    break;
                if(j == lt - 1)
                    add(i, 1);
            }
        }
        char na[5],af;
        int x, y;
        while(n--)
        {
            scanf("%s",na);
            if(na[0] == 'Q')
            {
                scanf("%d%d", &x, &y);
                if(y - x + 1 < lt)
                    printf("0\n");
                else
                    printf("%d\n", sum(y - lt + 1) - sum(x - 1));
            }
            else
            {
                scanf("%d",&x);
                scanf("%s",na);
                s[x - 1] = na[0];
                for(int i = max(1, x - lt + 1);i <= min(len, x + lt - 1);i++)
                {
                    add(i, sum(i-1) - sum(i));
                    for (int j = 0; j < lt; j++)
                    {
                        if (s[i + j - 1] != t[j])
                            break;
                        if (j == lt - 1)
                            add(i, 1);
                    }
                }
            }
        }
        printf("\n");
    }
}
