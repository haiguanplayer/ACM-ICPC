#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max = 200005;

int wa[Max],wb[Max],wsf[Max],wv[Max],sa[Max];
int ra[Max],height[Max],s[Max];
int str[Max],res[Max];

int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
//±¶ÔöO(nlogn)
void getsa(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)  wsf[i]=0;
    for(i=0;i<n;i++)  wsf[x[i]=r[i]]++;
    for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
    for(i=n-1;i>=0;i--)  sa[--wsf[x[i]]]=i;
    /***********************************/
    for(p=1,j=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)  y[p++]=i;
        for(i=0;i<n;i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;
        for(i=0;i<n;i++)  wv[i]=x[y[i]];
        for(i=0;i<m;i++)  wsf[i]=0;
        for(i=0;i<n;i++)  wsf[wv[i]]++;
        for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
        for(i=n-1;i>=0;i--)  sa[--wsf[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
    return;
}
void getheight(int *r,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++)  ra[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)
            k--;
        else
            k=0;
        j=sa[ra[i]-1];
        while(r[i+k]==r[j+k])
            k++;
        height[ra[i]]=k;
    }
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%d",&str[i]);
        str[n] = 0;
        for(int i = n+1;i < n+1+m;i++)
            scanf("%d",&str[i]);
        str[n+1+m] = 0;
        getsa(str,sa,n+1+m+1,130);
        getheight(str,n+1+m);
        int cnt = 0,p1 = 0,p2 = n+1;
        while(p1 < n && p2 < n+1+m)
        {
            if(str[p1] > str[p2])
                res[cnt++] = str[p1++];
            else if(str[p1] < str[p2])
                res[cnt++] = str[p2++];
            else
            {
                if(ra[p1] > ra[p2])
                    res[cnt++] = str[p1++];
                else
                    res[cnt++] = str[p2++];
            }
        }
        while(p1 < n)
            res[cnt++] = str[p1++];
        while(p2 < n+1+m)
            res[cnt++] = str[p2++];
        printf("Case %d: ",ca);
        for(int i = 0;i < cnt;i++)
            printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}
