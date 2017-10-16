#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int C_size = 26;
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
    void insert(char *str){
        int cur = 0;
        for(int i = 0;str[i] != '\0';i++){
            int d = str[i] - 'a';
            if(!ch[cur][d])
                ch[cur][d] = newnode();
            cur = ch[cur][d];
            val[cur]++;
        }
    }
    int query(char *str){
        int cur = 0;
        for (int i = 0;str[i] != '\0';i++){
            int d = str[i] - 'a';
            if(ch[cur][d])
                cur = ch[cur][d];
            else//Œﬁ∑®∆•≈‰
                return 0;
        }
        return val[cur];
    }
}trie;

int main(){
    int n,m;
    char str[15];
    while(~scanf("%d",&n)){
        trie.init();
        for(int i = 0;i < n;i++){
            scanf("%s",str);
            trie.insert(str);
        }
        scanf("%d",&m);
        while(m--){
            scanf("%s",str);
            printf("%d\n",trie.query(str));
        }
    }
    return 0;
}
