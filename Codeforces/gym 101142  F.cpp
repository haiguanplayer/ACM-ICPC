/*
题意：折矩形纸，求最少次数折到所给大小
思路：要求两种情况下的值，因为短边可能是由长边或短边折到的
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    //freopen("folding.in", "r", stdin);
    //freopen("folding.out", "w", stdout);
    long long W,H,w,h;
    while(~scanf("%lld%lld%lld%lld",&W,&H,&w,&h))
    {
        if(W < H)
            swap(W,H);
        if(w < h)
            swap(w,h);
        if(W < w || H < h)
        {
            printf("-1\n");
            continue;
        }
        long long WW = W,HH = H;
        long long sum1 = 0,sum2 = 0;
        while(W > w)
        {
            W  = (W+1) / 2;
            //w *= 2;
            sum1++;
        }
        while(H > h)
        {
            H = (H+1) / 2;
            //h *= 2;
            sum1++;
        }

        while(WW > h)
        {
            WW  = (WW+1) / 2;
            //w *= 2;
            sum2++;
        }
        while(HH > w)
        {
            HH = (HH+1) / 2;
            //h *= 2;
            sum2++;
        }
        printf("%lld\n",min(sum1,sum2));
    }
    return 0;
}



