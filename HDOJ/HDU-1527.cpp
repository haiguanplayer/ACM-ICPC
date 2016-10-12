
//Wythoff Game
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int minn = min(a,b);
        int k = abs(a-b);
        int t = (int)(k*(1.0 + sqrt(5.0))/2.0);
        if(t == minn)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
