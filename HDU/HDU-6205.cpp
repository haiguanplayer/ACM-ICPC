/*
���⣺����n�ѿ�Ƭ��ÿ�ѿ�Ƭ������ֵ����Ƭ�������ͳͷ���
�����ƶ���ĳ�ѿ�Ƭ��ʼȡ��ѭ������Ҫ��õ����Ľ�����ƶ�����
˼·����Ȼ��ѭ�����ͽ������ظ�һ�飬Ȼ��ɨ��ȡ�õ����ֵ
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
