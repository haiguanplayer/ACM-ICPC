#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;//360 350  -10
    if(abs(a-b) == 180)
        return 0 * printf("180\n");
    if(abs(a-b) < 360-abs(a-b))
        cout<<b-a<<"\n";
    else
    {
        if(b > a)
            cout<<-(360-abs(b-a))<<"\n";
        else
            cout<<(360-abs(b-a))<<"\n";
    }
    //cout << min(abs(a-b),) << "\n";
}