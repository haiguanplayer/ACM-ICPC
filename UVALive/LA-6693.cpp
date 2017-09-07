#include <bits/stdc++.h>
using namespace std;

const int N = 15;
char str[N][N];
int judge[N];
pair<int,int> a1,a2,b1,b2;
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        bool f1 = false,f2 = false;
        for(int i = 0;i < n;i++)
        {
            scanf("%s",str[i]);
            for(int j = 0;str[i][j] != '\0';j++)
            {
                if(!f1 && str[i][j] == '1')
                {
                    a1.first = i,a1.second = j;
                    f1 = 1;
                }
                if(f1 && str[i][j] == '1')
                    a2.first = i,a2.second = j;
                if(!f2 && str[i][j] == '2')
                {
                    b1.first = i,b1.second = j;
                    f2 = 1;
                }
                if(f2 && str[i][j] == '2')
                    b2.first = i,b2.second = j;
            }
        }
        int num = 0;
        for(int i = 0;i < n;i++)//左
            if(str[i][0] != '.')
                judge[num++] = str[i][0] - '0';
        for(int i = 1;i < n;i++)//下
            if(str[n-1][i] != '.')
                judge[num++] = str[n-1][i]-'0';
        for(int i = n-2;i >= 0;i--)
            if(str[i][n-1] != '.')//右
                judge[num++] = str[i][n-1] - '0';
        for(int i = n-2;i >= 1;i--)
            if(str[0][i] != '.')//左
                judge[num++] = str[0][i] - '0';
        if((judge[0] == 1 && judge[1] == 2 && judge[2] == 1 && judge[3] == 2)
           || (judge[0] == 2 && judge[1] == 1 && judge[2] == 2 && judge[3] == 1))
        {
            printf("-1\n");
            continue;
        }

        int ans = 0;
        ans += abs(a1.first-a2.first) + abs(a1.second - a2.second)+1;
        ans += abs(b1.first - b2.first) + abs(b1.second - b2.second)+1;
        bool flag = false;
        if(a1.first == a2.first && a2.first == b1.first && b1.first == b2.first)//同一行
        {
            if(!(a2.second < b1.second || b2.second < a1.second))//
                flag = true;
        }
        else if(a1.second == a2.second && a2.second == b1.second && b1.second == b2.second)//同一列
        {
            if(!(a2.first < b1.first || b2.first < a1.first))//
                flag = true;
        }

        if(flag)
            ans += 2;
        printf("%d\n",ans);
    }
    return 0;
}
