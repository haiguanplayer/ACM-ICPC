/*
题意：给你n堆卡片，每堆卡片都有数值（卡片数），和惩罚，
可以移动到某堆卡片开始取（循环），要求得到最大的结果的移动次数
思路：既然是循环，就将数组重复一遍，然后扫描取得的最大值
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int a[N*2],b[N*2];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]),a[i+n] = a[i];
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&b[i]);
            b[i] = a[i]-b[i];
            b[i+n] = b[i];
        }
        int maxn = -1000,suma = 0,sum = 0;
        int l,r,tmp = 1;
        for(int i = 1;i <= n*2;i++)
        {
            suma += a[i];
            sum += b[i];
            if(suma > maxn)
            {
                maxn = suma;
                l = tmp;
                r = i;
            }
            if(sum < 0)
            {
                suma = sum = 0;
                tmp = i+1;
                if(tmp > n+1)
                    break;
            }
        }
        printf("%d\n",l-1);
    }
    return 0;
}
