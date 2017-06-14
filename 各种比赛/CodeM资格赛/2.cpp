#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = (1<<21);
int a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    int x = a[0];
    sort(a,a+n);

    int pos = upper_bound(a+1,a+1+n,x)-a;
    int r = n-pos+1;
    int l = pos-1;//cout<<l<<" "<<r<<endl;
    int ans = 0;
    if(!r)
        ans = l/2;

    while(r > 0 && l > 1)
    {
        if(r%2)
            l--,r++;
        ans++;
        r >>= 1;
        l >>= 1;
    }
    printf("%d\n",ans);
    return 0;
}
