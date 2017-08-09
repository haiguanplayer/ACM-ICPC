#include<iostream>
#include<cstdio>

using namespace std;

const int N = 2e4+5;
int a[N];

int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        for(int i = 0;i < n*2;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %.2f\n",ca,0.5*n);

    }
    return 0;
}
