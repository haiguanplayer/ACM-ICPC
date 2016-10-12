#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int a[1005]={0};
    a[1]=3;
    a[2]=3;
    a[3]=5;
    a[4]=4;
    a[5]=4;
    a[6]=3;
    a[7]=5;
    a[8]=5;
    a[9]=4;
    a[10]=3;
    a[11]=6;
    a[12]=6;
    a[13]=8;
    a[14]=8;
    a[15]=7;
    a[16]=7;
    a[17]=9;
    a[18]=8;
    a[19]=8;
    a[20]=6;
    a[30]=6;
    a[40]=5;
    a[50]=5;
    a[60]=5;
    a[70]=7;
    a[80]=6;
    a[90]=6;
    a[100]=3+7;

    for(int i=20;i<100;i+=10)
    {
        for(int j=i+1;j<i+10;j++)
            a[j]=a[i]+a[j-i];
    }
    for(int i=100;i<1000;i+=100)
    {
        a[i]=a[i/100]+7;
        for(int j=i+1;j<=i+99;j++)
        {
            a[j]=a[i]+3+a[j-i];
        }
    }
    a[1000]=3+8;
    for(int i=2;i<=1000;i++)
        a[i]+=a[i-1];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}

