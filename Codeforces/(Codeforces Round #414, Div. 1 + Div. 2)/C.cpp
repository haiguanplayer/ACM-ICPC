#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a,b;
    string C;
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int la = a.length();
    int lb = b.length();
    for(int i = 0;i < la;i++)
        C.push_back('?');
    int u = 0,v = la-1;
    int g = (la-1)/2;
    int h = g+1;
    int c = 0;
    int ll = 0,rr = la-1;
    int le = 0,ri = la-1;
    while(c < la)
    {
        if(c&1)
        {
            if(a[ll] >= b[rr])
                C[ri--] = b[h++];
            else
                C[le++] = b[rr--];
        }
        else
        {
            if(a[ll] >= b[rr])
                C[ri--] = a[g--];
            else
                C[le++] = a[ll++];
        }
        c++;
    }/*
    for(int i = 0;i < la;i++)
    {
        if(u > la/2)
            c[i] = b[v--];
        else if(v < la/2)
            c[i] = a[u++];
        else
        {
            if(i&1)
            {
                if(a[u] > b[v])
                {
                    c[i] = a[u++];
                }
                else
                    c[i] = b[v--];
            }
            else
            {
                if(a[u] > b[v])
                {
                    c[i] = b[v--];
                }
                else
                    c[i] = a[u++];
            }
        }
    }*/
    cout<<C<<endl;
    return 0;
}
