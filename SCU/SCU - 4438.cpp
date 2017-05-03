#include<bits/stdc++.h>
using namespace std;

const int N = 1e6*5+5;
char s[N],str[N],ans[N];
int Next[N],pre[N];
void Getnext(int m)
{
    int i = 0,j = -1;
    Next[0] = -1;
    while(i < m)
    {
        if(j == -1 || s[i] == s[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}
int main()
{
    while(~scanf("%s %s",s,str))
    {
        int len1 = strlen(s);
        int len2 = strlen(str);
        Getnext(len1);
        for(int i = 0,j = 0,k = 0;i < len2;i++,k++)
        {
            ans[k] = str[i];
            while(j > 0 && str[i] != s[j])
                j = Next[j];
            if(str[i] == s[j])
                ++j;
            if(j == len1)//找到一个完整的s串
            {
                k -= len1;
                j = pre[k];
            }
            ans[k+1] = 0;
            pre[k] = j;
        }
        puts(ans);
    }
    return 0;
}
