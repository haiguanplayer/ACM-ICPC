#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 12;
const int eps = 1e-6;
struct node
{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    node operator - (node p)
    {
        return node(x-p.x,y-p.y);
    }
    int operator * (node p)
    {
        return x*p.y - y*p.x;
    }
}p[15];

int dis(int i,int j)
{
    return (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
}
int v[N][N][N][N][N][N];
bool check(int ii,int jj,int kk,int ll,int mm,int oo,int flag)
{
    int cnt[3] = {ii,mm,kk};
    int cnt2[3] = {jj,ll,oo};
    sort(cnt,cnt+3);sort(cnt2,cnt2+3);
    if(v[cnt[0]][cnt[1]][cnt[2]][cnt2[0]][cnt2[1]][cnt2[2]] == 0){
        if(flag) v[cnt[0]][cnt[1]][cnt[2]][cnt2[0]][cnt2[1]][cnt2[2]] = 1;
        return false;
    }
    else
        return true;
}
int main()
{
    int t,n;
    double len[3];
    scanf("%d",&t);
    for(int ca = 1;ca <= t;ca++)
    {

        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        int ans = 0;
        memset(v,0,sizeof(v));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(i != j)
                for(int k = 1;k <= n;k++)
                    if(i != k && j != k)
                    for(int h = 1;h <= n;h++)
                        if(i != h && j != h && k != h && dis(i,k) == dis(j,h))
                        for(int g = 1;g <= n;g++)
                            if(i != g && j != g && k != g && h != g)
                            for(int l = 1;l <= n && !check(i,j,k,h,g,l,0);l++)
                                if(i != l && j != l && k != l && h != l && g != l)
                                {
                                    if(dis(k,g) != dis(h,l) || dis(i,g) != dis(j,l))//不全等
                                        continue;
                                    if( ((p[k]-p[i])*(p[g]-p[k])) * ((p[h]-p[j])*(p[l]-p[h])) >= 0  //判断对称 如果对称 那么不行
                                        && ((p[g]-p[k])*(p[i]-p[g])) * ((p[l]-p[h])*(p[j]-p[l])) >= 0
                                        && ((p[i]-p[g])*(p[k]-p[i])) * ((p[j]-p[l])*(p[h]-p[j])) >= 0 )
                                        {
                                            len[0] = sqrt((double)dis(i,k));
                                            len[1] = sqrt((double)dis(i,g));
                                            len[2] = sqrt((double)dis(k,g));
                                            sort(len,len+3);
                                            if(len[0]+len[1] <= len[2]+eps)//如果三点共线
                                                break;
                                            ans++;
                                            check(i,j,k,h,g,l,1);
                                        }

                                }
        printf("Case %d: %d\n",ca,ans);
    }
}
