#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1000005;
char t[N],s[N];
int Next[N],d[15];//
void Getfail(int m)
{
    Next[0]=-1;
    int i=0,j=-1;
    while(i<m)
    {
        if(j==-1||t[i]==t[j])//Æ¥Åä
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP(int n,int m)
{
    int i=0,j=0,ans=0;
    while(i<n)
    {
        if(j==-1)
        {
            i++,j++;
        }
        if(s[i]==t[j])
        {
            if(j==m-1)
            {
                ans++;
                j=Next[j];
            }
            else
            {
                i++,j++;
            }
        }
        else
            j=Next[j];
    }
    return ans;
}

int main()
{

    int n;
    cin >> n >> t;
    int m = strlen(t);
    int len = 0;
    Getfail(m);
    for(int i = 2;i <= 16;i++)
    {
        len = 0;
        for(int j = 1;j <= n;j++)
        {
            int num = 0,x = j;
            while(x > 0)
            {
                d[num++] = x%i;
                x /= i;
            }

            for(int k = num-1;k >= 0;k--)
            {
                char tmp;
                if(d[k] > 9)
                    tmp = d[k]-10+'A';
                else
                    tmp = d[k] + '0';
                s[len++] = tmp;
            }
        }
        if(KMP(len,m))
            return 0 * printf("yes\n");
    }
    printf("no\n");
    return 0;
}
