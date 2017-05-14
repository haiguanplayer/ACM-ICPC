#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int sum = 0;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int x;
        scanf("%d",&x);
        if((x > a[0] && x < a[2]))
            sum++;
    }
    cout<<sum<<endl;
}
