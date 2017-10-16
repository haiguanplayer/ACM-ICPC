#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


const int N = 4000005;
long long ans;

struct Trie {
    int head[N],nxt[N],num[N];
    char ch[N];
    int trieN;
    void init(){
        trieN = 1; num[0] = head[0] = nxt[0] = 0;
    }
    int newnode(int u,char c){
        ++trieN;
        num[trieN] = 0;
        ch[trieN] = c;
        nxt[trieN] = head[u];
        head[u] = trieN;
        head[trieN] = 0;
        return trieN;
    }
    void insert(char *s) {
        num[0]++;
        int u = 0,v,len = strlen(s);
        for(int i = 0;i <= len;i++){
            bool flag = false;
            for(v = head[u];v; v = nxt[v])
                if(ch[v] == s[i]) { // 找到了
                    flag = true;
                    break;
                }
            if(!flag)
                v = newnode(u,s[i]);
            u = v;
            num[u]++;
        }
    }

    void dfs(int u,int depth) {
        if(head[u] == 0)
        ans += num[u] * (num[u] - 1) * depth;
        else {
            int sum = 0;
            for(int v = head[u];v; v = nxt[v])
                sum += num[v] * (num[u] - num[v]);
            ans += sum / 2 * (2 * depth + 1);
            for(int v = head[u];v; v = nxt[v])
                dfs(v,depth+1);
        }
    }
}trie;

char s[1005];
int main(){
    int n,ca = 0;
    while(~scanf("%d",&n) && n){
        trie.init();
        for(int i = 0;i < n;i++){
            scanf("%s",s);
            trie.insert(s);
        }
        ans = 0;
        trie.dfs(0, 0);
        printf("Case %d: %lld\n",++ca,ans);
    }
    return 0;
}
