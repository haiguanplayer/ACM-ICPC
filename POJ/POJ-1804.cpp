#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005;
int a[N],d[N],ans;

void merge(int l,int m,int r)
{
    int i = l,j = m+1,k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j]){
            d[k++] = a[j++];
            ans += m-i+1;
        }
        else
            d[k++] = a[i++];
    }
    while(i <= m) d[k++] = a[i++];
    while(j <= r) d[k++] = a[j++];
    for(int i = l;i <= r;i++)
        a[i] = d[i];
}
void merge_sort(int l,int r)
{
    if(l < r){
        int mid = (l+r)>>1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
    }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        ans = 0;
        merge_sort(1,n);
        printf("Scenario #%d:\n%d\n\n",ca,ans);
    }
}
