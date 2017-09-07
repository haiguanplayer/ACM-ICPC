#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long L,R;
    while(~scanf("%lld%lld",&L,&R))
    {
        if(R <= 1)
            printf("0\n");
        else if(R == 2)
            printf("1\n");
        else if(L == 0)
            printf("%lld\n",(R+1)/2);
        else
            printf("%lld\n",max(2ll,(R-L)/2+1));
    }
    return 0;
}
