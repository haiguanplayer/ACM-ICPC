#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
    int t,n,q,c;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        scanf("%d",&c);
        string p[205];
        for(int i = 0;i < c;i++)
            cin>>p[i];
        int m;
        string s;
        map<string,int> ma;
        map<string,string> judge;
        for(int i = 0;i < q;i++)//q��question�����
        {
            ma.clear();
            scanf("%d",&m);
            for(int j = 0;j < m;j++)
            {
                cin>>s;
                ma[s] = 1;
            }

            for(int j = 0;j < c;j++)
            {
                if(ma[p[j]])//���p[j]���yes��
                    judge[p[j]] += '1';
                else
                    judge[p[j]] += '0';
            }
        }

        //���
        string str,tmp = "",res;
        for(int i = 0;i < n;i++)
        {
            str = "";
            for(int j = 0;j < q;j++)
            {
                cin>>tmp;
                str += tmp;
            }

            int sum = 0;
            for(map<string,string>::iterator it = judge.begin();it != judge.end();it++)
            {
                if(str == it->second)
                {
                    sum++;
                    res = it->first;
                }
            }
            if(sum == 1)//ֻ��һ��������
                cout<<res<<endl;
            else
                cout<<"Let's go to the library!!"<<endl;
        }
    }
    return 0;
}
