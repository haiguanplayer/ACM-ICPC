#include<bits/stdc++.h>
using namespace std;

int a[105],b[105],vis[105];
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= k;i++)
    {
        scanf("%d",&b[i]);
    }
    if(k > 1)
        printf("Yes\n");
    else
    {
        for(int i = 1;i <= n;i++)
            if(a[i] == 0)
                a[i] = b[1];

        for(int i = 1;i <= n-1;i++)
        if(a[i] >= a[i+1])
            return 0 * printf("Yes\n");
        printf("No\n");
    }
    return 0;
}
