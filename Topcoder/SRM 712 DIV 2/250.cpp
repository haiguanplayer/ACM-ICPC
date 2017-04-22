
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

class RepeatNumberCompare {
public:
    string compare(int x1,int k1,int x2,int k2){
        string s1 = "",s2 = "",str1 = "",str2 = "";
        while(x1 > 0)
        {
            s1 += x1%10 + '0';
            x1 /= 10;
        }
        while(x2 > 0)
        {
            s2 += x2%10 + '0';
            x2 /= 10;
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        for(int i = 0;i < k1;i++)
            str1 = str1 + s1;
        for(int i = 0;i < k2;i++)
            str2  = str2 + s2;
        if(str1.length() > str2.length())
            return "Greater";
        else if(str1.length() < str2.length())
            return "Less";
        else
        {
            if(str1 > str2)
                return "Greater";
            else if(str1 < str2)
                return "Less";
            else
                return "Equal";
        }
    }
};
