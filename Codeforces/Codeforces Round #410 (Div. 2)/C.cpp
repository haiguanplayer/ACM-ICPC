#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
typedef long long ll;
ll a[N],res = 0;
/*
void gao(ll p,ll q)
{

}*/
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);

    ll num = a[1];
	for(ll i = 2; i <= n ; i++)
		num = __gcd(num,a[i]);
	if(num != 1)
		return 0*printf("YES\n0\n");


    for(int i = 1;i <= n;i++)
        a[i] %= 2;
    for(int i = 1 ; i <= n - 1 ; i++)
	{
		if(a[i])
		{
			if(a[i+1])
			{
			    //a[i] = a[i+1] = 0;
			    a[i+1] = 0;
			    res++;
			}
			else
            {
                //a[i] = 0;
                res += 2;
            }
		}
	}
    if(a[n])
        res += 2;
    printf("YES\n%lld\n",res);
    return 0;
}
