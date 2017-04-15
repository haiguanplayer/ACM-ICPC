#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 50005;


struct node
{
    int s,e,id;
    bool operator < (const node & p)const
    {
        if(s == p.s)
            return e < p.e;
        else
            return s < p.s;
    }
}p[N],tmp[4];

bool judge(node *a)
{
    node x = a[0];
    node y = a[1];
    node z = a[2];
    return x.e >= y.s && y.e >= z.s && x.e >= z.s;
}
bool cmp(node a,node b)
{
    return a.e > b.e;
}

int ind[N];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].s,&p[i].e);
            p[i].id = i+1;
        }
        int num = 0;
        sort(p,p+n);
        tmp[0] = p[0];
        tmp[1] = p[1];
        for(int i = 2;i < n;i++)
        {
            tmp[2] = p[i];
            sort(tmp,tmp+3);
            bool flag = false;
            if(judge(tmp))
                flag = true;
            sort(tmp,tmp+3,cmp);
            if(flag)
            {
                ind[num++] = tmp[0].id;
                swap(tmp[0],tmp[2]);
            }
        }

        sort(ind,ind+num);
        printf("%d\n",num);
        printf("%d",ind[0]);
        for(int i = 1;i < num;i++)
            printf(" %d",ind[i]);
        printf("\n");
    }
    return 0;
}
