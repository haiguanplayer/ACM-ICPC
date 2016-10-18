/*
输入g和l，求a，b满足gcd为g，lcm为l
直接看l % g == 0否
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int t,g,l;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&g,&l);
        if(l % g == 0)
            printf("%d %d\n",g,l);
        else
            printf("-1\n");
    }
    return 0;
}
