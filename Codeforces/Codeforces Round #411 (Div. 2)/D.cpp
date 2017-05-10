#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
char s[1000005];
int main()
{
    cin>>s;
    int len = strlen(s);
    long long b = 0,ans = 0;
    for(int i = len-1;i >= 0;i--)
    {
        if(s[i] == 'b')
            b = (++b)%MOD;
        else
        {
            ans = (ans+b)%MOD;
            b = (b<<1)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// abab  abbba   aab abba bbaba bbbbaa
// aaab   aabba  abbaba  bbababa  bbabba  bbabbabbaa  bbbbabbbabaa bbabbabaa bbbbababaa bbbbbbaabaa bbbbbbabbaaa
// abb bbab bbbba
