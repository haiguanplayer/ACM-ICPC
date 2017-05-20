#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
int x[N];
char str[N],p[N];

int Next[N];
void Getfail(int m)
{
    Next[0]=-1;
    int i=0,j=-1;
    while(i<m)
    {
        if(j==-1||p[i]==p[j])//Æ¥Åä
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
        if(str[i]==p[j])
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
    int n,a,b,L,R;
    cin>>n>>a>>b>>L>>R;
    scanf("%s",p);
    x[0] = b;
    if(x[0] >= L && x[0] <= R && x[0] % 2 == 0)
        str[0] = 'A';
    else if(x[0] >= L && x[0] <= R && x[0] % 2 == 1)
        str[0] = 'T';
    else if((x[0] < L || x[0] > R) && x[0] % 2 == 0)
        str[0] = 'G';
    else if((x[0] < L || x[0] > R) && x[0] % 2 == 1)
        str[0] = 'C';
    for(int i = 1;i < n;i++)
    {
        x[i] = (x[i-1]+a)%n;
        if(x[i] >= L && x[i] <= R && x[i] % 2 == 0)
            str[i] = 'A';
        else if(x[i] >= L && x[i] <= R && x[i] % 2 == 1)
            str[i] = 'T';
        else if((x[i] < L || x[i] > R) && x[i] % 2 == 0)
            str[i] = 'G';
        else if((x[i] < L || x[i] > R) && x[i] % 2 == 1)
            str[i] = 'C';
    }
    //cout<<str<<endl;
    int m = strlen(p);
    Getfail(m);
    cout<<KMP(n,m)<<endl;
    return 0;
}
