By huatian, contest: Codeforces Round #425 (Div. 2), problem: (B) Petya and Exam, Accepted, #
 #include<bits/stdc++.h>
using namespace std;

char c[30];
char s[100005],p[100005];
int cnt[150];

int main()
{
    int n;
    scanf("%s",c);
    for(int i = 0;c[i] != '\0';i++)
        cnt[c[i]] = 1;
    scanf("%s",s);
    int lens = strlen(s);
    bool ques = false;
    for(int i = 0;i < lens;i++)
        if(s[i] == '*')
            ques = true;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",p);
        int lenp = strlen(p);
        if(!ques)
        {
            if(lenp != lens)
            {
                printf("NO\n");
                continue;
            }
            bool flag = false;
            for(int i = 0;i < lenp;i++)
                if((s[i] == '?' && !cnt[p[i]]) || (s[i] != '?' && s[i] != p[i]))
                {
                    flag = true;
                    break;;
                }
            if(flag)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else
        {
            if(lenp < lens-1)
            {
                printf("NO\n");
                continue;
            }
            int k;
            bool flag = false;
            for(k = 0;s[k] != '*';k++)
                if((s[k] == '?' && !cnt[p[k]]) || (s[k] != '?' && s[k] != p[k]))
                {
                    flag = true;
                    break;
                }

            for(int i = 0;i < lens-1-k;i++)
                if((s[lens-1-i] == '?' && !cnt[p[lenp-1-i]]) || (s[lens-1-i] != '?' && s[lens-1-i] != p[lenp-1-i]))
                {
                    flag = true;
                    break;
                }
            for(int i = k;i <= lenp-1-(lens-1-k);i++)
                if(cnt[p[i]])
                {
                    flag = true;
                    break;;
                }
            if(flag)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
