#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

//string str;
char str[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int ca = 1;ca <= n;ca++)
    {
        memset(str,0,sizeof(str));
        scanf("%s",str);
        printf("Case %d: ",ca);
        int cnt,len = strlen(str);
        if(str[len-1] >= '1' && str[len-1] <= '4')
        {
            cnt = str[len-1] - '0';
            len--;
            bool a = false,e = false,i = false,o = false,u = false,v = false;
            for(int i = 0;i < len;i++)
            {
                if(str[i] == 'a')   a = true;
                if(str[i] == 'e')   e = true;
                if(str[i] == 'i')   i = true;
                if(str[i] == 'o')   o = true;
                if(str[i] == 'u')   u = true;
                if(str[i] == 'v')   v = true;
            }
            //bool flag = false;
            if(a)
            {
                for(int i = 0;i < len;i++)
                {
                    if(str[i] == 'a')
                    {
                        if(cnt == 1)
                            printf("иб");
                        else if(cnt == 2)
                            printf("ив");
                        else if(cnt == 3)
                            printf("иг");
                        else
                            printf("ид");
                    }
                    else
                        printf("%c",str[i]);
                }
            }
            else
            {
                if(o)
                {
                    for(int i = 0;i < len;i++)
                    {
                        if(str[i] == 'o')
                        {
                            if(cnt == 1)
                                printf("ин");
                            else if(cnt == 2)
                                printf("ио");
                            else if(cnt == 3)
                                printf("ип");
                            else
                                printf("и░");
                        }
                        else
                            printf("%c",str[i]);
                    }
                }
                else if(e)
                {
                    for(int i = 0;i < len;i++)
                    {
                        if(str[i] == 'e')
                        {
                            if(cnt == 1)
                                printf("ие");
                            else if(cnt == 2)
                                printf("иж");
                            else if(cnt == 3)
                                printf("из");
                            else
                                printf("ии");
                        }
                        else if(str[i] == 'v')
                            printf("u");
                        else
                            printf("%c",str[i]);
                    }
                }
                else if(i && !u)
                {
                    for(int i = 0;i < len;i++)
                    {
                        if(str[i] == 'i')
                        {
                            if(cnt == 1)
                                printf("ий");
                            else if(cnt == 2)
                                printf("ик");
                            else if(cnt == 3)
                                printf("ил");
                            else
                                printf("им");
                        }
                        else
                            printf("%c",str[i]);
                    }
                }
                else if(!i && u)
                {
                    for(int i = 0;i < len;i++)
                    {
                        if(str[i] == 'u')
                        {
                            if(cnt == 1)
                                printf("и▒");
                            else if(cnt == 2)
                                printf("и▓");
                            else if(cnt == 3)
                                printf("и│");
                            else
                                printf("и┤");
                        }
                        else
                            printf("%c",str[i]);
                    }
                }
                else if(i && u)
                {
                    int post1=0;
                    int post2=0;
                    for(int i=0;i<len-1;i++)
                    {
                        if(str[i]=='u')   post1=i;
                        if(str[i]=='i')   post2=i;
                    }
                    if(post1<post2)
                    {
                        for(int i=0;i<len;i++)
                        {
                            if(str[i]=='i')
                            {
                                if(cnt == 1)
                                    printf("ий");
                                else if(cnt == 2)
                                    printf("ик");
                                else if(cnt == 3)
                                    printf("ил");
                                else
                                    printf("им");
                            }
                            else printf("%c",str[i]);
                       }
                    }
                    else
                    {
                        for(int i=0;i<len;i++)
                        {
                            if(str[i]=='u')
                            {
                               if(cnt == 1)
                                    printf("и▒");
                                else if(cnt == 2)
                                    printf("и▓");
                                else if(cnt == 3)
                                    printf("и│");
                                else
                                    printf("и┤");
                            }
                            else printf("%c",str[i]);
                        }
                    }
                }
                else if(v && !e)
                {
                    for(int i = 0;i < len;i++)
                    {
                        if(str[i] == 'v')
                        {
                            if(cnt == 1)
                                printf("и╡");
                            else if(cnt == 2)
                                printf("и╢");
                            else if(cnt == 3)
                                printf("и╖");
                            else
                                printf("и╕");
                        }
                        else
                            printf("%c",str[i]);
                    }
                }
            }
        }
        else
            printf("%s",str);
        printf("\n");
            /*
            if(!flag)
            {
                if(str[i] == 'a')// || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'v')
                {
                    if(i+1 < len && (str[i+1] == 'i' || str[i+1] == 'o' || str[i+1] == 'n' || str[i+1] == 'r'))
                    {

                }
            }
            */
    }
    return 0;
}
