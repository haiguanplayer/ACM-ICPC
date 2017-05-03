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
//2
#include<bits/stdc++.h>
using namespace std;
int a[15] = {0,3,3,5,4,4,3,5,5,4};
int b[25] = {0,0,0,0,0,0,0,0,0,0,3,6,6,8,8,7,7,9,8,8};//十几
int c[15] = {0,0,6,6,5,5,5,7,6,6};//几十
int f[1005];
void Init()
{
    for(int i = 1;i <= 1000;i++)
    {
            int x = i;
            if(x == 1000)
            {
                f[i] += 11;
                continue;
            }
            int s[5] = {0},num = 0;
            while(x > 0)
            {
                s[num++] = x % 10;
                x /= 10;
            }
            if(s[2] == 0)
            {
                if(s[1] == 0)
                {
                    f[i] += a[s[0]];
                }
                else
                {
                    if(s[1] == 1)
                        f[i] += b[10+s[0]];
                    else
                        f[i] += c[s[1]] + a[s[0]];
                }
            }
            else//第一位不为0
            {
                if(s[1] == 0)//第二位等于0  00
                {
                    if(s[0] == 0)//x00
                        f[i] += a[s[2]] + 7 + a[s[0]];
                    else
                        f[i] += a[s[2]] + 7  + 3 + a[s[0]];
                }
                else
                {
                    if(s[1] == 1)
                        f[i] += a[s[2]] + 7  + 3 + b[10+s[0]];
                    else
                        f[i] += a[s[2]] + 7  + 3 + c[s[1]] + a[s[0]];
                }//4 7 3 6 4
            }
    }
}
int main()
{
    Init();
    //for(int i = 100;i <= 200;i++)
    //cout<<f[i]<<endl;
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1;i <= n;i++)
            sum += f[i];
        //cout<<f[n]<<endl;
        printf("%d\n",sum);
    }
    return 0;
}

