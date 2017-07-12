#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b ? gcd(b,a%b):a;
}
int main(){
    long long T,a,b,c,k;
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> k;
        if(c % gcd(b,gcd(a,k-1)) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
