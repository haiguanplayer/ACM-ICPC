#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e2+5;
struct node
{
    string str;
    int val;
    bool operator < (const node & p)const
    {
        return val < p.val;
    }
}p[N];

int main()
{
    int t,s,m,d;
    cin>>t;
    while(t--)
    {
        vector<string> v;
        int sum = 0;
        scanf("%d%d%d",&s,&m,&d);
        for(int i = 0;i < s;i++)
            cin>>p[i].str>>p[i].val;
        sort(p,p+s);
        v.push_back(p[s/2].str);
        sum += p[s/2].val;
        for(int i = 0;i < m;i++)
            cin>>p[i].str>>p[i].val;
        sort(p,p+m);
        v.push_back(p[m/2].str);
        sum += p[m/2].val;
        for(int i = 0;i < d;i++)
            cin>>p[i].str>>p[i].val;
        sort(p,p+d);
        v.push_back(p[d/2].str);
        sum += p[d/2].val;
        cout<<sum<<" ";
        for(int i = 0;i < v.size()-1;i++)
            cout<<v[i]<<" ";
        cout<<v[v.size()-1]<<endl;

    }
    return 0;
}
