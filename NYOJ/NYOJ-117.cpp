//（离散化+树状数组）
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 1000005;
struct node
{
    int pos;
    ll val;
}nod[N];
int C[N],r[N];
int n;


bool cmp(node a,node b)
{
    if(a.val == b.val)
        return a.pos < b.pos;
    return a.val < b.val;
}


int lowbit(int t)
{
    return t&(-t);
}


void add(int t)
{
    while(t <= N)
    {
        C[t] += 1;
        t += lowbit(t);
    }
}



//求得前面小于当前的数的个数
ll getnum(int t)
{
    ll ans = 0;
    while(t > 0)
    {
        ans += C[t];
        t -= lowbit(t);
    }
    return ans;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(C,0,sizeof(C));

        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&nod[i].val);
            nod[i].pos = i;
        }
        sort(nod+1, nod+1+n,cmp);//先sort
        for(int i = 1;i <= n;i++)//离散化处理
            r[nod[i].pos] = i;
        ll ans = 0,k;
        for(int i = 1;i <= n;i++)
        {
            add(r[i]);
            k = i - getnum(r[i]);
            ans += k;
        }
        printf("%lld\n",ans);
    }
    return 0;
}








//归并排序求逆序数

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1000005;
LL sum, a[N],b[N];
void merge(LL *a,int x,int m,int y)
{
    int p = x,q = m+1,i = x;
    while(p <= m && q <= y)
    {
        if(a[p] <= a[q])
            b[i++] = a[p++];
        else
        {
            sum += q - i;
            b[i++] = a[q++];
        }
    }

    while(p <= m)
        b[i++] = a[p++];
    while(q <= y)
        b[i++] = a[q++];
    for(int k = x;k <= y;k++)
        a[k] = b[k];
}
void merge_sort(LL *a,int x,int y)
{
    if(y > x)
    {
        int m = x + (y-x)/2;
        int p = x,q = m,i = x;
        merge_sort(a,x,m);//将前半部分排序
        merge_sort(a,m+1,y);//将前半部分排序
        merge(a,x,m,y);//合并前后两个部分
    }
}
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lld",&a[i]);
        sum = 0;
        merge_sort(a,0,n-1);
        printf("%lld\n",sum);
    }
    return 0;
}
