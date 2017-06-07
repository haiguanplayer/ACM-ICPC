#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;
int main(){
    ll x,y,l,r;
    cin >> x >> y >> l >> r;
    v.push_back(l-1);
    v.push_back(r+1);
    for(ll i = 1,j;;i *= x){
        for(j = 1;;j *= y){
            if(i+j >= l && i+j <= r)
                v.push_back(i+j);
            if(j > r/y)
                break;
        }
        if(i > r/x)
            break;
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i = 1;i < v.size();i++)
        ans = max(ans,v[i]-v[i-1]-1);
    cout<<ans<<endl;
    return 0;
}
