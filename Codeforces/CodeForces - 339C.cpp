#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;
string s;
vector <int> t;
int m,flag = 0,a[N];
void dfs (int c , int l , int r , int pre) {
    if (c == m) {
        flag = true;
        return ;
    }
    if (flag) return ;
    for (int i = 0 ; i < t.size() ; i ++) {
        if (t[i] == pre) continue;
        if (c & 1) {
            if (r + t[i] > l) {
                a[c] = t[i];
                dfs (c  + 1 , l  , r + t[i] , t[i]);
                if (flag) return ;
            }
        }
        else {
            if (l + t[i] > r) {
                a[c] = t[i];
                dfs (c + 1 , l + t[i] , r , t[i]);
                if (flag) return ;
            }
        }
    }
}
int main () {
    cin >> s >> m;
    for (int i = 0 ; i < 10 ; i ++)
        if (s[i] == '1')
            t.push_back (i + 1);
    dfs (0 , 0 , 0 , 0);
    if (flag) {
        puts ("YES");
        for (int i = 0 ; i < m ; i ++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        puts ("NO");
    return 0;
}
