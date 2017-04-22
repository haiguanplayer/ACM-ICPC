#include<bits/stdc++.h>
using namespace std;
bool pa(string s)
{
    string ss = s;
    reverse(ss.begin(),ss.end());
    return ss == s;
}
int main()
{
    string s,ss;
    cin>>s;
    for(int i = 0;i < s.size();i++)
    {
        ss = s;
        for(char j = 'a';j <= 'z';j++)
        {
            if(ss[i] == j)
                continue;
            ss[i] = j;
            if(pa(ss))
                return 0 * printf("YES\n");
            ss = s;
        }
    }
    printf("NO\n");
}
