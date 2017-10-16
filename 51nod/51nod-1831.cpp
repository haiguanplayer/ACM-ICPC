#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    for(int i = 2;i <= sqrt(n);i++)
        if(n % i == 0)
            return false;
    return true;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n == 1 || (isprime(n) && (n != 2 && n != 17)) || (!isprime(n) && (n == 16 || n == 34 || n == 289)))
            printf("NIE\n");
        else
            printf("TAK\n");
    }
    return 0;
}

//打表代码
int ok[1010];

void init()
{
    ok[0]=ok[1]=0;
    for(int i=2; i<=1000; i++)
    {
        if(!ok[i-1])
        {
            ok[i]=1;
            continue;
        }
        for(int j=2; j<=i/2; j++)    //分成等量j份，每份i/j个
            if(i%j==0 && !ok[i/j])
            {
                ok[i]=1;
                break;
            }
    }
}

void print()
{
    for(int i=0; i<=100; i++)
        printf("i=%d\tok[%d]=%d\n",i,i,ok[i]);
}
