/*
题意：一个01矩阵，表示灯的亮灭状态，每次操作可以改变一个十字形状内
的五个灯的状态。问能否将所有灯熄灭。
分析：高斯消元法
对于每个灯的亮灭有影响的开关就是它附近十字形内的五个开关。
所以对于每个灯可以列一个方程，即周围五个开关异或起来的结果应该
可以使该灯熄灭。
就是利用线性代数知识，写出增广矩阵，化为阶梯形矩阵，
有下到上依次解出各未知量。
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
        if ( i == n ) return 0; //由于控制矩阵可逆，所以x[]是有唯一解的，此处也可省略

        if ( row != k )
        {
            for ( j = k; j < n; j++ )
                swap ( a[k][j], a[row][j] );
            swap ( b[k], b[row] );
        }

        for ( i = k + 1; i < n; i++ )
        {
            if ( a[i][k] == 0 ) continue; //按行处理
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
