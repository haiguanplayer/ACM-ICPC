#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll h[100005];
ll n,a,b;

bool check(ll k){
    ll cnt = k*b;
    int num = upper_bound(h+1,h+1+n,cnt) - h;
    ll sum = 0;
    for(int i = num;i <= n;i++)
    {
        //printf("h[i]=%lld\n",h[i]);
        ll tmp = h[i] - cnt;
        sum += (tmp+a-b-1) / (a-b);
    }
    //printf("%lld %lld\n",sum,k);
    return sum <= k;
}
int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i = 1;i <= n;i++)
        scanf("%lld",&h[i]);

    sort(h+1,h+1+n);
    ll l = 0,r = INT_MAX,mid;
    while(l < r){
        mid = (l+r)/2;
        if(!check(mid))
            l = mid+1;
        else
            r = mid;
    }
    printf("%lld\n",r);
    return 0;
}
//2 3   2 3  1 2  1 1       5 5 3 5
