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
    while(n*(n+1)/2 < a)//�ҵ�����������������ŵĶ���
        n++;
    int cnt = n*(n+1)/2 - a;//����任���Ǹ���ƶ������ŵġ����롱
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
