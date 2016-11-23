#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    char str[1005];
}p[1005];
int main()
{
    int t,n,m,q;
    cin >> t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                p[i].str[j] = '.';
        int a,b,x,y;
        while(q--)
        {
            scanf("%d",&a);
            if(a == 1)
            {
                scanf("%d%d%d",&b,&x,&y);
                if(b == 1)
                    p[x].str[y] = 'w';
                else
                    p[x].str[y] = 'b';
            }
            else
            {
                scanf("%d%d",&x,&y);
                swap(p[x],p[y]);
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j < m;j++)
                printf("%c",p[i].str[j]);
            printf("%c\n",p[i].str[m]);
        }

    }
}
