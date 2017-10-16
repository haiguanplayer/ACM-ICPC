#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        int x,y;
        if(n == 2)
        {
            scanf("%d%d",&x,&y);
            if(x < y)
                swap(x,y);
            if(y == (int)((x-y)*1.0*(sqrt(5.0)+1)/2))
                printf("Watson\n");
            else
                printf("Sherlock\n");
        }
        else
        {
            int ans = 0;
            for(int i = 0;i < n;i++)
            {
                scanf("%d",&x);
                ans ^= x;
            }
            if(ans)
                printf("Sherlock\n");
            else
                printf("Watson\n");
        }
    }
    return 0;
}
