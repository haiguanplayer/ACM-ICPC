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
        if(!vis[s[i]])//��û���ֹ���ǰ����ַ�
        {
            while(!a.empty())
            {
                if(c[a.back()] == 0 || a.back() < s[i])
                    break;
                //���ջ���ַ��ں��滹�� ���� �ֵ�����ڵ��ڵ�ǰ�ַ�
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
