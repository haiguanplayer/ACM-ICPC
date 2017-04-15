#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string s;
int c[127],vis[127];
vector<char> a;
int main()
{
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n;i++)
        c[s[i]]++;
    for(int i = 0;i < n;i++)
    {
        c[s[i]]--;
        if(!vis[s[i]])//还没出现过当前这个字符
        {
            while(!a.empty())
            {
                if(c[a.back()] == 0 || a.back() < s[i])
                    break;
                //如果栈顶字符在后面还有 并且 字典序大于等于当前字符
                vis[a.back()] = 0;
                a.pop_back();
            }
            a.push_back(s[i]);
            vis[s[i]] = 1;
        }
    }
    cout << string(a.begin(),a.end()) << endl;
    return 0;
}
