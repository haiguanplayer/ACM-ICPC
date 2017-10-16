#include<bits/stdc++.h>
using namespace std;


const int N = 400005;
const int C_size = 26;

const int MOD = 20071027;
vector<int> ans;
int len[N],dp[N];

struct Trie{
    int trieN;
    int ch[N][C_size], val[N];
    void init(){
        memset(ch[0],0,sizeof(ch[0]));
        trieN = -1;
        newnode();
    }
    int newnode(){
        memset(ch[++trieN], 0, sizeof(ch[0]));
        val[trieN] = 0;//fail[trieN] = 0;
        return trieN;
    }
    void insert(char *str,int index){
        int cur = 0;
        for(int i = 0;str[i] != '\0';i++){
            int d = str[i] - 'a';
            if(!ch[cur][d])
                ch[cur][d] = newnode();
            cur = ch[cur][d];
        }
        val[cur] = index;//×Ö·û´®±àºÅ
    }
    void query(char *str,int len){
        int cur = 0;
        for (int i = 0;i < len;i++){
            int d = str[i] - 'a';
            if(!ch[cur][d])
                return;
            cur = ch[cur][d];
            if(val[cur]) ans.push_back(val[cur]);
        }
        //return val[cur];
    }
}trie;

char str[300005],s[4005];
int main(){
    int n,ca = 0;
    while(~scanf("%s",&str)){
        scanf("%d",&n);
        trie.init();
        for(int i = 1;i <= n;i++){
            scanf("%s",s);
            len[i] = strlen(s);
            trie.insert(s,i);
        }
        memset(dp,0,sizeof(dp));
        int ls = strlen(str);
        dp[ls] = 1;
        for(int i = ls-1;i >= 0;i--)
        {
            ans.clear();
            trie.query(str+i,ls-i);
            for(int j = 0;j < ans.size();j++)
                dp[i] = (dp[i] + dp[i + len[ans[j]]]) % MOD;
        }
        printf("Case %d: %d\n",++ca,dp[0]);
    }
    return 0;
}
