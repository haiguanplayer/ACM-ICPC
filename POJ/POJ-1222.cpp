/*
���⣺һ��01���󣬱�ʾ�Ƶ�����״̬��ÿ�β������Ըı�һ��ʮ����״��
������Ƶ�״̬�����ܷ����е�Ϩ��
��������˹��Ԫ��
����ÿ���Ƶ�������Ӱ��Ŀ��ؾ���������ʮ�����ڵ�������ء�
���Զ���ÿ���ƿ�����һ�����̣�����Χ���������������Ľ��Ӧ��
����ʹ�õ�Ϩ��
�����������Դ���֪ʶ��д��������󣬻�Ϊ�����ξ���
���µ������ν����δ֪����
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 30;
int a[N][N],b[N];

void Init()
{
    int t1,t2,t3,t4;
    for(int i = 0;i < 30;i++)
    {
        t1 = i / 6;
        t2 = i % 6;
        for(int j = 0;j < 30;j++)
        {
            t3 = j / 6;
            t4 = j % 6;
            if(abs(t1-t3) + abs(t2-t4) <= 1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}

int Gauss ( int n, int a[][N], int b[] )
{
    int i, j, k, row;
    for ( k = 0; k < n; k++ )
    {
        for ( i = k; i < n; i++ )
            if ( a[i][k] == 1 ) { row = i; break; }
        if ( i == n ) return 0; //���ڿ��ƾ�����棬����x[]����Ψһ��ģ��˴�Ҳ��ʡ��

        if ( row != k )
        {
            for ( j = k; j < n; j++ )
                swap ( a[k][j], a[row][j] );
            swap ( b[k], b[row] );
        }

        for ( i = k + 1; i < n; i++ )
        {
            if ( a[i][k] == 0 ) continue; //���д���
            for ( j = k + 1; j < n; j++ )
                a[i][j] ^= a[k][j];
            b[i] ^= b[k];
        }
    }

    b[n-1] = b[n-1] / a[n-1][n-1];
    for ( i = n - 2; i >= 0; i-- )
    {
        for ( j = i + 1; j < n; j++ )
            b[i] ^= ( a[i][j] * b[j] );
        b[i] = b[i] / a[i][i];
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        for(int i = 0;i < 30;i++)
            scanf("%d",&b[i]);

        printf("PUZZLE #%d\n",ca);
        Init();
        Gauss(30,a,b);

        for(int i = 1;i <= 30;i++)
        {
            printf("%d ",b[i-1]);
            if(i % 6 == 0)
                printf("\n");
        }
    }
    return 0;
}
