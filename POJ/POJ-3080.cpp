#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[4005][205];
int len,Next[5005];

void Getfail(char *p)
{
    int m = strlen(p);
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < m)
    {
        if(j == -1 || p[i] == p[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}
int KMP(char *p,char *s)
{
    Getfail(p);
    int m = strlen(p),n = strlen(s);
    int i = 0,j = 0,ans = 0;
    while(i < n)
    {
        if(j == -1)
            i++,j++;
        if(s[i] == p[j])
        {
            if(j == m-1)
                return 1;
            else
                i++,j++;
        }
        else
            j = Next[j];
    }
    return 0;
}

int main()
{
    int t,N;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        char mins[255],temp[255],Min[205]="";
        int minn = 4500;
        for(int i = 0;i < N;i++)
        {
            scanf("%s",str[i]);
            len = strlen(str[i]);
            if(minn > len)
            {
                minn = len;
                strcpy(mins,str[i]);
            }
        }

        bool flag = false;

        for(int i = 2;i <= minn;i++)
        {
            for(int j = 0;i+j <= minn;j++)
            {
                int ans = 0;
                strncpy(temp,mins+j,i);
                temp[i] = '\0';
                Getfail(temp);
                for(int k = 0;k < N;k++)
                {
                    if(KMP(temp,str[k]))
                        ans++;
                    else
                        break;
                }
                if(ans == N)
                {
                    //printf("*****\n");
                    flag = true;
                    if(strlen(Min) < strlen(temp))
                        strcpy(Min,temp);
                    else if(strlen(Min) == strlen(temp) && strcmp(Min,temp) > 0)
                        strcpy(Min,temp);
                }
            }
        }
        if(flag)
            printf("%s\n",Min);
        else
            printf("no significant commonalities\n");
    }
    return 0;
}
