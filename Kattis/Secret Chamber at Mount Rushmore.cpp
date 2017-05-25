#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int d[N][N];

int main()
{
    int m,n;
    cin >> m >> n;
    char a,b;
    char aa[55],bb[55];

    for(int i = 0;i < 26;i++)
        d[i][i] = 1;
    for(int i = 0;i < m;i++)
    {
        cin >> a >> b;
        d[a-'a'][b-'a'] = 1;
    }

    for(int k = 0;k < 26;k++)
        for(int i = 0;i < 26;i++)
            for(int j = 0;j < 26;j++)
                d[i][j] |= d[i][k] & d[k][j];

    for(int i = 0;i < n;i++)
    {
        cin >> aa >> bb;
        int lena = strlen(aa);
        int lenb = strlen(bb);
        if(lena != lenb)
        {
            printf("no\n");
            continue;
        }
        bool flag = true;
        for(int j = 0;j < lena;j++)
        {
            if(!d[aa[j]-'a'][bb[j]-'a'])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
