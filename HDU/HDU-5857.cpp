//moni or zhuxishu
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];
int main()
{
    int t,n,m;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);

        while(m--)
        {
            double res = 0;
            int l1,l2,r1,r2;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            int mid,mid1,mid2,len1,len2;
            int L = r1-l1+1 + r2-l2+1;
            if(l1 > l2)
                swap(l1,l2),swap(r1,r2);
            if(l2 > r1)
            {
                len1 = r1-l1+1;
                if(L & 1)
                {
                    mid = L/2 + 1;
                    if(mid > len1)
                        res = a[l2-1 + mid-len1];
                    else
                        res = a[l1+mid-1];
                }
                else
                {
                    mid1 = L/2,mid2 = L/2+1;
                    if(mid1 > len1)
                        res += a[l2-1 + mid1-len1];
                    else
                        res += a[l1+mid1-1];
                    if(mid2 > len1)
                        res += a[l2-1 + mid2-len1];
                    else
                        res += a[l1+mid2-1];
                    res /= 2.0;
                    /*
                    if(mid2 < len1)
                        res = (a[l1+mid1-1]+a[l1+mid2-1])/2.0;
                    else if(mid1 > len1)
                        res = (a[l2-1 + mid1-len1] + a[l2-1 + mid2-len1])/2.0;
                    else
                        res = (a[l1+mid1-1]+a[l2-1 + mid2-len1])/2.0;
                    */
                }
            }
            else
            {
                if(r1 > r2)
                    swap(r1,r2);
                len1 = l2-l1,len2 = r1-l2+1;
                if(L & 1)
                {
                    mid = L/2 + 1;
                    if(mid <= len1)//第一段
                        res = a[l1+mid-1];
                    else if(mid <= len1+2*len2)//重合的第二段
                        res = a[l2 + (mid-len1+1)/2 -1];
                    else//第三段
                        res = a[r1 + mid-len1-2*len2];
                }
                else
                {
                    mid1 = L/2,mid2 = L/2+1;
                    if(mid1 <= len1)
                        res += a[l1+mid1-1];
                    else if(mid1 <= len1+2*len2)
                        res += a[l2+(mid1-len1+1)/2-1];
                    else
                       res += a[r1+mid1-len1-2*len2];
                    if(mid2 <= len1)
                        res += a[l1+mid2-1];
                    else if(mid2 <= len1+2*len2)
                        res += a[l2+(mid2-len1+1)/2-1];
                    else
                        res += a[r1+mid2-len1-2*len2];
                    res /= 2.0;
                }
            }
            printf("%.1f\n",res);
        }
    }
    return 0;
}
