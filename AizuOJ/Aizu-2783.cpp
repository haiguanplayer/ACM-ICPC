#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int main()
{
    int a;
    cin>>a;
    int n = 0;
    while(n*(n+1)/2 < a)//找到这个数属于完整括号的对数
        n++;
    int cnt = n*(n+1)/2 - a;//距离变换到那个最长移动的括号的“距离”
    for(int i = 0;i < n-cnt;i++)
        printf(")");
    printf("(");
    for(int i = n-cnt+1;i < n+1;i++)
        printf(")");
    for(int i = n+1;i < n*2;i++)
        printf("(");
    printf("\n");
    return 0;
}
