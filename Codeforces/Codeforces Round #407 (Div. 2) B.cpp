//so easy and diffcult
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+5;
int a[N];
int b,q,m;
bool judge(int t)
{
    int l = 1, r = m,mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] > t)
            r = mid-1;
        else if(a[mid] < t)
            l = mid+1;
        else
            return true;
    }
    return false;
}
int main()
{
    long long l;
    cin>>b>>q>>l>>m;
    bool flag = false;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&a[i]);

    }
    sort(a+1,a+1+m);

        long long res = 0,t = b,cnt = 0;
        while(t <= l && -t <= l)
        {
            if(!judge(t))
                res++;
            t *= 1ll*q;
            if(cnt++ >= 100000)
            {
                if(res == 1)
                    return 0*printf("1\n");
                else if(res >= 32)
                    return 0*printf("inf\n");
                else
                    return 0*printf("0\n");
            }

        }
        printf("%d\n",res);
}
