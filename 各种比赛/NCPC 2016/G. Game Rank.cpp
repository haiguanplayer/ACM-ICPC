#include<bits/stdc++.h>
using namespace std;

int num(int ra)
{
    if(ra <= 25 && ra >= 21)
        return 2;
    if(ra <= 20 && ra >= 16)
        return 3;
    if(ra <= 15 && ra >= 11)
        return 4;
    if(ra <= 10 && ra >= 1)
        return 5;
    return 0;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int ra = 25,cnt = 0;
    for(int i = 0;i < len;i++)
    {
        if(ra == 0)
            break;
        if(s[i] == 'W')
        {
            cnt++;
            if(i >= 2 && s[i-1] == 'W' && s[i-2] == 'W' && ra > 5)
                cnt++;
            if(cnt > num(ra))
            {
                cnt -= num(ra);
                --ra;
            }
        }
        else
        {
            if(ra < 20 || (ra == 20 && cnt > 0))
            {
                cnt--;
                if(cnt < 0)
                {
                    ++ra;
                    cnt = num(ra)+cnt;
                }
            }
        }
    }
    if(ra == 0)
        puts("Legend");
    else
        cout<<ra<<"\n";
}