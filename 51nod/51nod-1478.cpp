#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

const int N = 1e6+5;
char s[N];
int dp[N];
stack<int> st;
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1);
    int maxn = 0,cnt = 1;
    for(int i = 1;i <= len;i++)
    {
        if(s[i] == '(')
            st.push(i);
        else if(!st.empty())
        {
            int t = st.top();
            st.pop();
            dp[i] = dp[t-1]+i-t+1;
            if(dp[i] > maxn)
                maxn = dp[i],cnt = 1;
            else if(dp[i] == maxn)
                cnt++;
        }
    }
    printf("%d %d\n",maxn,cnt);
}
