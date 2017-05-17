#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
char str[N];
int a[N];
bool check(int k,int len)
{
    int sum = k*9;
    int s = 0;
    for(int i = 0;i < len;i++)
    {
        sum += a[i];
        s += sum % 10;
        sum /= 10;
    }
    while(sum)
    {
        s += sum % 10;
        sum /= 10;
    }
    return s <= k*9;
}
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    reverse(str,str+len);
    for(int i = 0;i < len;i++)
        a[i] = (str[i]-'0')*9;
    for(int i = 0;i < len;i++)
        a[i+1] += a[i]/10,a[i] %= 10;
    if(a[len])
        len++;
    int l = 0,r = len*2,mid;
    while(r-l > 1)
    {
        mid = (l+r)>>1;
        if(check(mid,len))
            r = mid;
        else
            l = mid;
    }
    printf("%d\n",r);
    return 0;
}
