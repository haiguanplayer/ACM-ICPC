#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int t,x,y,a,b;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>a>>b;
        if(x == 1 || y == 1)
        {
            printf("INF\n");
            continue;
        }
        else if(x == 2 && y == 2 && (a >= 2 || b >= 2))
        {
            printf("INF\n");
            continue;
        }
        else
        {
            int ans = 0;
            while(a >= x || b >= y)
            {
                if(a >= x)
                {
                    int tmp = a/x;
                    ans += tmp;
                    a = a%x+tmp;
                    b += tmp;
                }
                if(b >= y)
                {
                    int tmp = b/y;
                    ans += tmp;
                    a += tmp;
                    b = b%y+tmp;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
