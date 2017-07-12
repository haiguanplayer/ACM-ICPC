#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int p[N],myset[N];
map<int,int> ma;
map<int,int> id;
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++)
        scanf("%d",&p[i]),ma[p[i]] = 1,id[p[i]] = i;
    sort(p+1,p+1+n);
    int gre = max(a,b),les = min(a,b);
    int ga,gb;
    if(gre == a)
        ga = 0,gb = 1;
    else
        ga = 1,gb = 0;
    for(int i = 1;i <= n;i++)
    {
        if(ma[p[i]])
        {
            if(ma[gre-p[i]])
                ma[p[i]] = ma[gre-p[i]] = 0,myset[id[p[i]]] = myset[id[gre-p[i]]] = ga;
            else if(ma[les-p[i]])
                ma[p[i]] = ma[les-p[i]] = 0,myset[id[p[i]]] = myset[id[les-p[i]]] = gb;
            else
                return 0 * printf("NO\n");
        }
    }

    printf("YES\n");/*
    for(int i = 1;i <= n;i++)
        printf("%d ",myset[i]);
    printf("\n");*/
    return 0;
}
