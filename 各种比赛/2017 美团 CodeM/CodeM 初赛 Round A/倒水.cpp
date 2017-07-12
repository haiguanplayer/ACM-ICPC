#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int t[N],c[N];
int n,T,C;
//minn = (t*c+T*C)/(c+C)
//C = (t-minn)*c/(minn-T)
int main()
{
    cin >> n;
    cin >> T >> C;
    bool high = false,low = false;
    int minn = (int)1e9;//,maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d %d",&t[i],&c[i]);
        if(t[i] > T)
            high = true;
        if(t[i] < T)
            low = true;
        minn = min(minn,t[i]);
        //maxn = max(maxn,t[i]);
    }
    if(!high && !low)//温度相同
    {
        printf("Possible\n");
        printf("%.4f\n",(double)T);
    }
    else if(high && !low)//都比T大
    {
        long long need = 0;
        for(int i = 1;i <= n;i++)
            need += (t[i]-minn)*c[i];
        //cout<<need << " need"<<endl;
        if(1ll*C*(minn-T) < need)
            printf("Impossible\n");
        else
        {
            printf("Possible\n");
            printf("%.4f\n",(double)minn);
        }
    }
    else if(!high && low)//都比T小，就把水用完
    {
        double a = 1.0*T*C,b = 1.0*C;
        for(int i = 1;i <= n;i++)
            a += t[i]*c[i],b += c[i];
        printf("Possible\n");
        printf("%.4f\n",a/b);
    }
    else
        printf("Impossible\n");
    return 0;
}
