//easy game or a law
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        if(n <= 2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
