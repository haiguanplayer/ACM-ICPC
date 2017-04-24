#include<bits/stdc++.h>
using namespace std;

class MakePalindrome {
public:
    vector <string> constructMinimal(string card){
        //vector<int> a(256);
        int a[280] = {0};
        for(int i = 0;i < card.size();i++)
            a[(int)card[i]]++;

        string s = "";
        vector<string> ans;
        for(int i = 'a';i <= 'z';i++)
        {
            for(int j = 1;j*2 <= a[i];j++)
                s += (char)i;

            if(a[i]&1)
            {
                ans.push_back(string());
                ans.back() += (char)i;
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
