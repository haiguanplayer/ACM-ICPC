#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
    int t,n,k;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d",&n,&k);
        printf("Case #%d:",ca);
        printf(" %d %d",k*2,k);
        for(int i = k-1;i >= 1;i--)
            printf(" %d",i);
        for(int i = k+1;i < k*2;i++)
            printf(" %d",i);
        for(int i = k*2+1;i <= n;i++)
            printf(" %d",i);
        cout<<endl;
    }
}
