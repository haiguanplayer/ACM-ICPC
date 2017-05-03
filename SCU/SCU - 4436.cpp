#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    while(cin >> n)
    {
        double sum = 0;
        for(int i = 0;i < n;i++)
        {
            cin >> x;
            sum += sqrt(x);
        }
        if(sum == (long long)sum)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
