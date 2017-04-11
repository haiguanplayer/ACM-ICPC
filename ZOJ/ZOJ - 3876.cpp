#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t,year;
    int ans[10] = {6,9,6,5,5,5,5};

    cin>>t;
    while(t--)
    {
        int d = 2,y = 1928;
        scanf("%d",&year);
        if(year == y)
            cout<<ans[d]<<endl;
        else
        {
            while(y++ < year)
            {
                if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                    d = (d+366)%7;
                else
                    d = (d+365)%7;
            }
            cout<<ans[d]<<endl;
        }
    }
}
