#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

struct point
{
    double x,y;
    int id;
}p[N],stk[N],base;
int n,top;
char s[N];

double length(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double across(point c,point a,point b)
{
    return (a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x);
}
bool cmp(point a,point b)
{
    if(across(base,a,b) == 0)//三点共线
        return length(base,a) < length(base,b);
    return across(base,a,b) > 0;
}
void getside()
{
    stk[0] = p[0];
    stk[1] = p[1];
    top = 1;
    for(int i = 2;i < n;i++)
    {
        while(top > 0 && across(stk[top-1],stk[top],p[i]) <= 0)//上一个确定的点是凸的
            top--;
        stk[++top] = p[i];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        base = {1000,1000};
        int minn = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id = i;
            if(p[i].y < base.y || (p[i].y == base.y && p[i].x < base.x))
            {
                base = p[i];
                minn = i;
            }
        }

        swap(p[minn],p[0]);
        sort(p+1,p+n,cmp);
        getside();

        if(n < 3 || (n == 3 && top+1 == n))
            puts("NO");
        else
        {
            for(int i = 0;i < n;i++)
                s[i] = 'B';
            s[n] = '\0';
            if(top+1 < n)//凸包点数小于n，说明凸包中包含一些点
                for(int i = 0;i <= top;i++)//将凸包上的点和不在凸包上的各分一类
                s[stk[i].id] = 'A';
            else if(top+1 == n)
                s[stk[0].id] = s[stk[2].id] = 'A';

            puts("YES");
            puts(s);
        }
    }
}
