#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,h;
    cin>>n>>h;
    for(int i = 1;i <= n-1;i++)
    {
        double s = sqrt(1.0*i*h*h/n);
        printf("%.12f ",s);
    }
    cout<<endl;
}
