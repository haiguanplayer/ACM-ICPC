#include<bits/stdc++.h>
using namespace std;

class MakePalindrome {
public:
    string constructMinimal(string card){
        int a[280];
        for(int i = 0;i < card.size();i++)
            a[card[i]]++;

        string s = "";
        vector<string> ans;
        for(int i = 'a';i <= 'z';i++)
        {
            for(int j = 1;j*2 <= a[i];j++)
                s += (char)i;

            if(a[i]&1)
            {
                string tmp = "";
                tmp += (char)i;
                ans.push_back(tmp);
            }
        }

        if(ans.empty())
            ans.push_back(string());//push¿Õ
        for(int i = 0;i < s.size();i++)
        {
            ans[0] += s[i];
            ans[0] = s[i] + ans[0];
        }
        return ans;
    }
};
