#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[10005] = {0};
int main()
{
    int x=10;
    for(int i=1;i<=10;i++){
        a[i]=x-i+1;
        x*=10;
    }
    int n;
    while(~scanf("%d",&n)){
        int ans = 0,pos=0;
        while(n-1 >= a[pos])
            pos++;
        pos--;
        ans += pos;
        printf("%d\n",ans+n);
    }
    return 0;
}
