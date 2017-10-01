#include<bits/stdc++.h>
using namespace std;

const int N = 1100005;
char s[N];
int num[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        int len = strlen(s+1);
        stack<int> st;
        long long ans = 0;
        for(int i = 1;i <= len;i++)
        {
            if(s[i] == '(')
                num[i] = 0,st.push(i);
            else
            {
                if(st.empty())
                    num[i] = 0;
                else
                {
                    int pos = st.top();
                    st.pop();
                    ans += num[pos-1]+1;
                    num[i] = num[pos-1]+1;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
