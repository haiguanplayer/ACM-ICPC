#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

const int N = 1e5;
long long m[N];
int L[N],R[N];
set<pair<long long,int> > s;

void del(int x)
{
    s.erase(make_pair(m[x],x));
    R[L[x]] = R[x];
    L[R[x]] = L[x];
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        scanf("%lld",&m[i]);
        s.insert(make_pair(m[i],i));
        L[(i+1) % n] = i;
        R[i] = (i+1) % n;
    }
    long long ans = 0;
    for(int i = 0;i < n/3;i++)
    {
        int j = s.rbegin()->second;
        long long a = m[L[j]];
        long long b = m[j];
        long long c = m[R[j]];
        ans += b;
        del(L[j]);
        del(R[j]);
        s.erase(make_pair(m[j],j));
        m[j] = a+c-b;
        s.insert(make_pair(m[j],j));
    }
    cout << ans << endl;
    return 0;
}
