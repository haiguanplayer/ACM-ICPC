#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
    int p,e,i,d;
    int ca = 1;
    while(~scanf("%d%d%d%d",&p,&e,&i,&d) && (p != -1|| e != -1 || i != -1 || d != -1))
    {
        printf("Case %d: the next triple peak occurs in ",ca++);
        int n = (5544*p + 14421*e + 1288*i - d + 21252) % 21252;
        if(n == 0)
            printf("21252 days.\n");
        else
            printf("%d days.\n",n);
    }
    return 0;
}
