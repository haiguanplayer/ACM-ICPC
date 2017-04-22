#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string s[N],ss[N];
int Cal(string t,string tt)
{
    int l = t.size(),ll = tt.size();
    for(int i = 0,j;i+l < ll;i++)
    {
        for(j = 0;j < l;j++)
        {
            if(tt[i+j] != t[j])//¾¹È»ÍüÁËi+j£¬°¡°¡°¡°¡
                break;
        }
        if(j == l)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>s[i];
        ss[i] = s[i];
    }
    for(int i = 0;i < n;i++)
        ss[i] = ss[i] + s[i];
    int minn = 0x3f3f3f3f,cnt;
    for(int i = 0;i < n;i++)
    {
        int sum = 0;
        for(int j = 0;j < n;j++)
        {
            if(i == j)
                continue;

            cnt = Cal(s[i],ss[j]);
            //cout<<cnt<<endl;
            if(cnt == -1)
                return 0 * printf("-1\n");
            sum += cnt;
        }
        minn = min(minn,sum);
    }
    printf("%d\n",minn);
    return 0;
}
