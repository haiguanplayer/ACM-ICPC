#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char str[N];
map<pair<string,string>,int> a;
pair<string,string> p;
string h[N];
int main()
{
    int cnt = 0;
    while(gets(str))
    {
        string u = "",v = "";
        int i;
        for(i = 0;str[i] != '-';i++)
            u += str[i];
        for(i = i+2;str[i] != ':';i++)
            v += str[i];
        if(u > v)
            swap(u,v);
        p.first = u;
        p.second = v;
        a[p] = cnt;

        for(i = i+2;str[i] != '\0';i++)
            if(str[i] >= 'A' && str[i] <= 'Z')
                h[cnt] += str[i] + 32;
            else if((str[i] >= 'a' && str[i] <= 'z'))
                h[cnt] += str[i];
            else
                h[cnt] += ' ';
        cnt++;
    }
    int sum = 0,ans = 0;
    for(map<pair<string,string>,int>::iterator it = a.begin();it != a.end();it++)
    {
        sum++;
        int num = it->second;
        int len = h[num].length();
        bool flag = false;
        for(int i = 0;i < len-1;i++)
        {
            int tt = 0;
            if((i >= 1 && h[num][i-1] == ' ') || i == 0)
            while( h[num][i] == 'h' && h[num][i+1] == 'e')
            {
                tt++;
                if((h[num][i+2] == ' ' || i+2 == len) && tt > 1)
                {
                    flag = true;
                    break;
                }
                i+=2;
            }
            if(flag)
                break;
        }

        if(flag)
            ans++;
    }
    //printf("%d %d\n",sum,ans);
    double res = 1.0*ans*100.0/sum;
    res = round(res);
    printf("%.0f%%\n",res);
    return 0;
}
/*
A->B: Hello!
A->C: Hi!
B->A: Hehe
B->D: Hei!
D->B: How are you?
A->C: Hi???
A->C: Are you there?
B->D: Hehehei!
D->B: What does hehehei mean?
F->E: I want to hehehehehe yah.

(i == 0 ||  h[num][i-1] == ' ') &&
B->A: iHehe
F->E: I want to hehehehehe yah.
B->D: Hehehe
A->C: Hehe
D->F: hhh
E->G: hehehe
*/
