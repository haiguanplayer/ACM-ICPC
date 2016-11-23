#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

bool palin(string s)
{
    string ss = s;
    reverse(s.begin(),s.end());
    return ss == s;
}
int main()
{
    string str,s,temp;
    cin >> str;
    for(int i = 0;i <= str.size();i++)
        for(char j = 'a';j <= 'z';j++)
        {
            temp = str;
            s = "";s += j;
            temp.insert(i,s);
            if(palin(temp))
            {
                cout<<temp<<endl;
                return 0;
            }
        }
    printf("NA\n");
    return 0;
}
