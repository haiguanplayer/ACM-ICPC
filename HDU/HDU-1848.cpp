#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;
int f[N],SG[N],hashh[N];

void getSG(int n)
{
    memset(SG,0,sizeof(SG));
    for(int i = 1;i <= n;i++)
    {
        memset(hashh,0,sizeof(hashh));
        for(int j = 1;f[j] <= i;j++)
            hashh[SG[i-f[j]]] = 1;

        int num = 0;
        while(hashh[num])
            num++;
        SG[i] = num;
    }
}
int main()
{
    f[0] = f[1] = 1;
    for(int i = 2;i <= 16;i++)
        f[i] = f[i-1] + f[i-2];
    getSG(1000);

    int m,n,p;
    while(~scanf("%d%d%d",&m,&n,&p) && (m||n||p))
    {
        if((SG[m] ^ SG[n] ^ SG[p]) == 0)
            printf("Nacci\n");
        else
            printf("Fibo\n");
    }
    return 0;
}
