//problem is when yuantu and butu hui tonggou,namely edge (n-1)*n+1)/2 is even
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        if(((n-1)*n+1)/2 % 2 == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
