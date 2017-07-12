#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
char a[N];
int main()
{
    scanf("%s",a+1);
    int n = strlen(a+1);
    int l = 1,r = n;
    while(l <= n && a[l] == '0')
        l++;
    while(r >= 0 && a[r] == '0')
        r--;
    int u = 1,d = 1;
    for(int i = r-1;i >= l;i--)
        if(a[i] == '1')
            u = min(u,d)+1;
        else
            d = min(u,d)+1;
    printf("%d\n",u*2-1);
    return 0;
}
