#include <iostream>
#include <cstdio>
#include <cstring>
#include<cmath>
using namespace std;

const int N = 85;
char str[N];
int n,m,a[N][N],x[N];

inline int gcd(int a,int b){return b == 0?a:gcd(b,a%b);}
inline int lcm(int a,int b){return a / gcd(a,b) *b;}

void Gauss(int mod)
{
    int i,j;
    int LCM;
    int ta,tb;
    int row,col,max_r;
    int tmp;
    for(row = 0,col = 0;row < m && col < n;row++,col++)
    {
        max_r = row;
        for(i = row+1;i < m;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(max_r != row)
        {
            for(j = row;j < n+1;j++)
                swap(a[row][j],a[max_r][j]);
        }
        if(a[row][col] == 0)
        {
            row--;
            continue;
        }
        for(i = row+1;i < m;i++)
        {
            if(a[i][col] != 0)
            {
                LCM = lcm(a[i][col],a[row][col]);
                ta = LCM / abs(a[i][col]);
                tb = LCM / abs(a[row][col]);
                if(a[i][col]*a[row][col] < 0)
                    tb = -tb;
                for(j = col;j<n+1;j++)
                {
                    a[i][j]=((a[i][j]*ta - a[row][j]*tb) % mod + mod) % mod;
                }
            }
        }
    }

    for(i = n-1;i >= 0;i--)
    {
        tmp = a[i][n];
        for(j = i+1;j < n;j++)
        {
            if(a[i][j] != 0)
                tmp -= a[i][j]*x[j];
            tmp = (tmp%mod+mod)%mod;
        }
        while(tmp % a[i][i] != 0)
            tmp += mod;
        x[i] = tmp/a[i][i] % mod;
    }
}

int pow_mod(int a,int n,int mod)
{
    int ans=1;
    while(n)
    {
        if(n&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int N,p;
    cin >> N;
    while(N--)
    {
        scanf("%d%s",&p,str);
        n = m = 0;
        int len = strlen(str);
        for(int i = 0;i < len;i++)
        {
            if(str[i] == '*')
                a[i][len] = 0;
            else
                a[i][len] = str[i] - 'a' + 1;
            for(int j = 0;j < len;j++)
                a[i][j] = pow_mod(i+1,j,p);
        }

        n = m = len;
        Gauss(p);
        for(int i = 0;i < len-1;i++)
            printf("%d ",x[i]);
        printf("%d\n",x[len-1]);
    }
    return 0;
}
