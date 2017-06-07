#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N];
int main(){
    int n,m;
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]),sum += a[i];
    cin >> m;
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        if(sum <= u)
            return 0 * printf("%d\n",u);
        else if(sum <= v)
            return 0 * printf("%d\n",sum);
    }
    printf("-1\n");
    return 0;
}
