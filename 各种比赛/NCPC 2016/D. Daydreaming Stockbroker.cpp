#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d,p;
    cin >> d;
    long long money = 100;
    int pre = 500;
    for(int i = 0;i < d;i++)
    {
        cin >> p;
        if(p > pre)
            money += min(money/pre,100000ll)*(p-pre);
        pre = p;
    }
    cout << money << "\n";
    return 0;
}