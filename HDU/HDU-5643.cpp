#include<iostream>
#include<cstdio>
using namespace std;
int a[5005];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 2;i <= n;i++)
        {
            a[i] = (a[i-1]+n-i+1)%i;
        }
        printf("%d\n",a[n]+1);
    }
    return 0;
}
