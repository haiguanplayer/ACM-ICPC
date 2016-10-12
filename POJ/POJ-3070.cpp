#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Mod = 10000;
struct Matrix
{
    int a[2][2];
}ans,base;

Matrix Multi(Matrix p,Matrix q)
{
    Matrix tmp;
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            tmp.a[i][j] = 0;
            for(int k = 0;k < 2;k++)
                tmp.a[i][j] = (tmp.a[i][j] + p.a[i][k]*q.a[k][j]) % Mod;
        }
    }
    return tmp;
}

int Fast_Matrix(int n)
{
    base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    base.a[1][1] = 0;
    ans.a[0][0] = ans.a[1][1] = 1;
    ans.a[0][1] = ans.a[1][0] = 0;
    while(n)
    {
        if(n & 1)
            ans = Multi(ans,base);

        base = Multi(base,base);
        n >>= 1;
    }
    return ans.a[0][1];
}
int main()
{
    int n;
    while(~scanf("%d",&n) && n!= -1)
    {
        printf("%d\n",Fast_Matrix(n));
    }
    return 0;
}
