#include<bits/stdc++.h>
using namespace std;

const int N = 3000005;
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
    void del(char *str){
        int cur = 0;
        for(int i = 0;str[i] != '\0';i++){
            int d = str[i] - 'a';
            if(!ch[cur][d])
                return;
            cur = ch[cur][d];
        }
        int x = 0;
        for(int i = 0;str[i] != '\0';i++){
            int d = str[i] - 'a';
            if(!ch[x][d])
                return;
            int pre = x;
            x = ch[x][d];
            val[x] -= val[cur];
            if(val[x] == 0)
                ch[pre][d] = 0;
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
    int n;
    char str[35],type[10];
    scanf("%d",&n);
    trie.init();
    for(int i = 0;i < n;i++){
        scanf("%s %s",type,str);
        if(type[0] == 'i')
            trie.insert(str);
        else if(type[0] == 'd')
            trie.del(str);
        else{
            if(trie.query(str))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
