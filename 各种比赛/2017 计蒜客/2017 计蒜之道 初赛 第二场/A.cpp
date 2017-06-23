#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector< pair<int,int> > p;
set< pair<int,int> > q;
int main()
{
    int num1,num2,num3,num4;
    cin>>num1>>num2>>num3>>num4;
    int k,d;
    cin>>k>>d;
    int n = num1+num2+num3+num4;

    for(int i = 1;i <= num1;i++)
        p.push_back(make_pair(0,i-1));
    for(int i = 1;i <= num4;i++)
        p.push_back(make_pair(3,i-1));
    for(int i = 1;i <= num3;i++)
        p.push_back(make_pair(2,i-1));
    for(int i = 1;i <= num2;i++)
        p.push_back(make_pair(1,i-1));

    int pos,tmp,sum = 0;
    for(int i = 1;i <= 6;i++)
    {
        for(int j = i;j <= 6;j++)
        {
            pos =  (i+j - 1)%4;

            if(pos == 0)
            {
                tmp = 0;
            }
            else if(pos == 3)
            {
                tmp = num1;
            }
            else if(pos == 2)
            {
                tmp = num1+num4;
            }
            else
            {
                tmp = num1+num4+num3;
            }
            q.clear();
            int yy = tmp+min(i,j);
            while(q.size() < 6)
            {
                q.insert(p[yy++]);
                yy %= n;
                q.insert(p[yy++]);
                yy = (yy+6)%n;
            }

            if(q.count(make_pair(k-1,d)) && q.count(make_pair(k-1,d-1)))
                sum++;
        }
    }
    cout<<sum<<endl;
}
