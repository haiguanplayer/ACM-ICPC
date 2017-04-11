#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;

const int N = 205;

int mark[N<<2];
double sum[N<<2],Hash[N<<2];

struct line
{
    double l,r,h;
    int d;
    line(double l = 0,double r = 0,double h = 0,int d = 0):l(l),r(r),h(h),d(d){}
    bool operator < (const line & p)const
    {
        return h < p.h;
    }
}s[N];

void Push(int n,int left,int right)
{
    if(mark[n])
        sum[n] = Hash[right+1]-Hash[left];
    else if(left == right)
        sum[n] = 0;
    else
        sum[n] = sum[n<<1] + sum[n<<1|1];
    return;
}
void Update(int l,int r,int d,int n,int left,int right)
{
    if(l <= left && right <= r)
    {
        mark[n] += d;
        Push(n,left,right);
        return;
    }
    int m = (left+right)>>1;
    if(l <= m)
        Update(l,r,d,n<<1,left,m);
    if(r > m)
        Update(l,r,d,n<<1|1,m+1,right);
    Push(n,left,right);
    return;
}
int Search(double k,double *x,int n)
{
    int l = 0,r = n-1,m;
    while(left <= right)
    {
        m = (l+r)/2;
        if(x[m] == k)
            return m;
        if(x[m] > k)
            r = m-1;
        else
            l = m+1;
    }
    return -1;
}
int main()
{
    int n,ca = 0;
    double x1,x2,y1,y2;
    while(~scanf("%d",&n) && n)
    {
        int num = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            Hash[num] = x1;
            s[num++] = line(x1,x2,y1,1);
            Hash[num] = x2;
            s[num++] = line(x1,x2,y2,-1);
        }

        sort(Hash,Hash+num);
        sort(s,s+num);

        int index = 1;
        for(int i = 1;i < num;i++)
            if(Hash[i] != Hash[i-1])
                Hash[index++] = Hash[i];

        double ans = 0;

        for(int i = 0;i < num;i++)
        {
            int L = Search(s[i].l,Hash,index);
            int R = Search(s[i].r,Hash,index)-1;
            Update(L,R,s[i].d,1,0,index-1);
            ans += sum[1]*(s[i+1].h - s[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++ca,ans);
    }
    return 0;
}
