#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 26;
queue<int> q;
vector<string> vec;
bool vis[N];
struct Trie{
    int trieN;
    int ch[N][M], val[N], fail[N];
    void init() {
        memset(vis,0,sizeof(vis));
        trieN = -1;
        newnode();
    }
    int newnode() {
        memset(ch[++trieN], 0, sizeof(ch[0]));
        val[trieN] = fail[trieN] = 0;
        return trieN;
    }
    void insert(const string &str, int index) {
        int cur = 0;
        for (int i = 0;str[i];i++) {
            int d = str[i] - 'a';
            if (!ch[cur][d])
                ch[cur][d] = newnode();
            cur = ch[cur][d];
        }
        if (val[cur]) vis[index] = 1;
        else val[cur] = index;
    }
    void build() {
        for (int i = 0;i < M;i++) {
            if (ch[0][i])
                q.push(ch[0][i]);
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0;i < M;i++) {
                int &next = ch[cur][i];
                if (next) {
                    fail[next] = ch[fail[cur]][i];
                    q.push(next);
                }
                else next = ch[fail[cur]][i];
            }
        }
    }
    void query(const string &str) {
        int cur = 0, tmp;
        for (int i = 0;str[i];i++) {
            int d = str[i] - 'a';
            tmp = cur = ch[cur][d];
            while (tmp && ~val[tmp]) {
                if (val[tmp] != -1) vis[val[tmp]] = 1;
                val[tmp] = -1;
                tmp = fail[tmp];
            }
        }
    }
}ac;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ac.init();
        int n;
        cin >> n;
        vec.resize(n+1);
        int maxlen = 0,maxi;
        for(int i = 1;i <= n;i++){
            cin >> vec[i];
            if (vec[i].size() > maxlen){
                maxlen = vec[i].size();
                maxi = i;
            }
        }
        vis[maxi] = 1;
        for(int i = 1;i <= n;i++){
            if (i != maxi)
                ac.insert(vec[i],i);
        }
        ac.build();
        ac.query(vec[maxi]);
        bool flag = 1;
        for(int i = 1;i <= n && flag;i++){
            if (!vis[i]) flag = 0;
        }
        if(flag) cout << vec[maxi] << '\n';
        else cout << "No\n";
    }
    return 0;
}
