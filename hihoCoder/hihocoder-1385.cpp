#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<cctype>
using namespace std;

int main()
{
    string str;
    map<string,int> m;
    map<string,int>::iterator i;
    while(getline(cin,str))
    {

        if(str == "####")
        {
            string s;
            int ans = 0;
            for(i = m.begin();i != m.end();i++)
            {
                if(i->second > ans)
                {
                    ans = i->second;
                    s = i->first;
                }
            }
            cout<<s<<":"<<ans<<endl;
            m.clear();
        }
        else
        {
            int len = str.size();

            for(int i = 0;i < len;i++)
            {
                string tmp = "";
                if(isalpha(str[i]))
                {
                    int pos = i;
                    while(isalpha(str[pos]))
                        tmp += str[pos++];

                    bool flag = true;
                    while(true)
                    {
                        if(str[pos] == ',' || str[pos] == '.' || pos >= len)
                        {
                            flag = false;
                            break;
                        }
                        if(isalpha(str[pos]))
                            break;
                        pos++;
                    }

                    i = pos - 1;
                    if(flag)//中间是空格隔开的
                    {
                        tmp += " ";
                        while(isalpha(str[pos]))
                            tmp += str[pos++];
                        m[tmp]++;
                    }
                }
            }
        }

    }
    return 0;
}
