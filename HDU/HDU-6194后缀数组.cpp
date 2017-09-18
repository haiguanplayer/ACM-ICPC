#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Max = 200005;

int wa[Max],wb[Max],wsf[Max],wv[Max],sa[Max];
int rankk[Max],height[Max];
char str[Max];

int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void getsa(int *r,int *sa,int n,int m)
{
    int i, j, p, *x = wa, *y = wb;
    for (i = 0; i < m; ++i) wsf[i] = 0;
    for (i = 0; i < n; ++i) wsf[x[i]=r[i]]++;
    for (i = 1; i < m; ++i) wsf[i] += wsf[i-1];
    for (i = n-1; i >= 0; --i) sa[--wsf[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wsf[i] = 0;
        for (i = 0; i < n; ++i) wsf[wv[i]]++;
        for (i = 1; i < m; ++i) wsf[i] += wsf[i-1];
        for (i = n-1; i >= 0; --i) sa[--wsf[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}
void calheight(int r[], int n)
{
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rankk[sa[i]] = i;
    for (i = 0; i < n; height[rankk[i++]] = k)
        for (k?k--:0, j = sa[rankk[i]-1]; r[i+k] == r[j+k]; k++);
}
int len,a[Max],d[Max][40];
void rmq_init(int* A, int n)
{
    for(int i = 0; i < n; ++i)
        d[i][0] = A[i];
    for(int j = 1; (1<<j) <= n; ++j)
        for(int i = 0; i + (1<<j) - 1 < n ; ++i)
            d[i][j] = min(d[i][j-1], d[i + (1<< (j-1))][j-1]);
}

int ASK(int l,int r)
{
    int k = 0;
    while((1<<(k+1)) <= r-l + 1)
        ++k;
    return min(d[l][k], d[r-(1<<k) + 1][k]);
}

int ask(int l,int r)
{
    if (l == r)
        return len - sa[r];
    return ASK(l + 1, r);
}
int main()
{
    int T,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        scanf("%s",str);
        len = strlen(str);
        for(int i = 0;i < len;i++)
            a[i] = str[i]-'a'+1;
        a[len] = 0;
        getsa(a,sa,len+1,30);
        calheight(a,len);
        rmq_init(height,len+1);

        ll ans = 0;
        for(int i = 1;i + k - 1 <= len;i++)
        {
            ans += ask(i,i+k-1);
            if(i-1 > 0)
                ans -= ask(i-1,i+k-1);
            if(i+k <= len)
                ans -= ask(i,i+k);
            if(i-1 > 0 && i+k <= len)
                ans += ask(i-1,i+k);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
