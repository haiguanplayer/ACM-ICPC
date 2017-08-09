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

