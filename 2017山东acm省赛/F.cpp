#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int t,a,b,c;
    cin >> t;
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0)
        {
            if(b == 0)
            {
                if(c == 0)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
            else
            {//bx+c=0
                double x = (-1.0)*c/b;
                if(x == (ll)x)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            continue;
        }

        double deta = b*b*1.0-4.0*a*c;
        if(deta < 0)
            printf("YES\n");
        else
        {
            double x1 = ((-1.0)*b+sqrt(deta))/(2.0*a);
            double x2 = ((-1.0)*b-sqrt(deta))/(2.0*a);
            if(x1 == (ll)x1 && x2 == (ll)x2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
