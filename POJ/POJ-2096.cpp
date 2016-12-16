/*
��n��bug��s����ϵͳ��bug�������ޣ���ÿ��ֻ�ܷ���һ��bug��
Ҫ����ǵ���s����ϵͳ�з���n��bugʱ����Ҫ������������ƽ��������
dp[i][j]��ʾ�Ѿ���j����ϵͳ�з���i��bugʱ��������������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1005;
double dp[N][N];

int main()
{
    int n,s;
    cin >> n >> s;
    double p1, p2, p3, p4;
    for(int i = n;i >= 0;i--)
        for(int j = s;j >= 0;j--)
        {
            if( i == n && j == s)
                continue;
            p1 = 1.0*(n-i)*(s-j) / (n*s);
            p2 = 1.0*(n-i)*j / (n*s);
            p3 = 1.0*i*(s-j) / (n*s);
            p4 = 1.0*i*j / (n*s);
            dp[i][j] = (p1*dp[i+1][j+1] + p2*dp[i+1][j] + p3*dp[i][j+1] + 1) / (1-p4);
        }
    printf("%.4f\n",dp[0][0]);
    return 0;
}
