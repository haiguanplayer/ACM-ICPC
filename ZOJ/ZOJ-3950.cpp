//copy from snowy_smile
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int casenum, casei;
int mon[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 }, s[2][13];
int pre[10000][13][32];
int sum[10000][13][32];
int leap(int y)
{
    if (y % 400 == 0)return 1;
    if (y % 100 == 0)return 0;
    if (y % 4 == 0)return 1;
    return 0;
}
inline int check(int y, int m, int d)
{
    int ret = 0;
    while (y)
    {
        ret += y % 10 == 9;
        y /= 10;
    }
    while (m)
    {
        ret += m % 10 == 9;
        m /= 10;
    }
    while (d)
    {
        ret += d % 10 == 9;
        d /= 10;
    }
    return ret;
}
void init(int y1, int m1, int d1, int y2, int m2, int d2)
{
    mon[2] = 28 + leap(y1);
    int tmp = 0;
    while (y1 != y2 || m1 != m2 || d1 != d2)
    {
        pre[y1][m1][d1] = tmp;
        tmp += check(y1, m1, d1);
        sum[y1][m1][d1] = tmp;
        if (++d1 > mon[m1])
        {
            d1 = 1;
            if (++m1 > 12)
            {
                m1 = 1;
                mon[2] = 28 + leap(++y1);
            }
        }
    }
}
int main()
{
    init(2000, 1, 1, 10000, 1, 1);
    scanf("%d", &casenum);
    for (casei = 1; casei <= casenum; ++casei)
    {
        int y1, m1, d1, y2, m2, d2;
        scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);
        int ans = sum[y2][m2][d2] - pre[y1][m1][d1];
        printf("%d\n", ans);
    }
    return 0;
}
