#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        int a = 0,b = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&x);
            if(x == 1)
                a++;
            else if(x == 2)
                b++;
        }
        if(a > b)
            printf("Kobayashi\n");
        else if(a < b)
            printf("Tohru\n");
        else
            printf("Draw\n");
    }
}
