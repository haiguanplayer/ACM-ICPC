#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

char str[1005],num[5];
int main()
{
    while(gets(str))
    {
        stack<char> s;
        stack<double> sum;
        int len = strlen(str);
        double a,b;
        for(int i = len-1;i >= 0;i--)
        {
            if(isdigit(str[i]) || str[i] == '.')
            {
                while(str[i] != ' ')
                {
                    s.push(str[i--]);
                }
                int n = 0;
                while(!s.empty())
                {
                    num[n++] = s.top();
                    s.pop();
                }
                num[n] = '\0';
                sum.push(atof(num));
            }
            else
            {
                switch(str[i])
                {
                case '*':
                    a = sum.top();
                    sum.pop();
                    b = sum.top();
                    sum.pop();
                    sum.push(a*b);
                    break;
                case '/':
                    a = sum.top();
                    sum.pop();
                    b = sum.top();
                    sum.pop();
                    sum.push(a/b);
                    break;
                case '+':
                    a = sum.top();
                    sum.pop();
                    b = sum.top();
                    sum.pop();
                    sum.push(a+b);
                    break;
                case '-':
                    a = sum.top();
                    sum.pop();
                    b = sum.top();
                    sum.pop();
                    sum.push(a-b);
                    break;
                }
            }
        }
        printf("%.2f\n",sum.top());
    }
    return 0;
}
