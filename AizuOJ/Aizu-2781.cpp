#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int MAXN = 210;
const int  INF = 0x3f3f3f;

int dirt[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
char map[MAXN][MAXN];
int vis[MAXN][MAXN];
int n,m;//,flag;
int sx,sy;
int num1 = INF,num2 = INF;


struct node{
    int x,y,num;
};
void BFS(){
    vis[sx][sy]=1;
    queue<node>q;
    node a,b;
    a.x=sx,a.y=sy,a.num = 0;
    q.push(a);
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            b.x = a.x+dirt[i][0];
            b.y = a.y+dirt[i][1];
            b.num = a.num+1;
            if(b.x<0||b.x>=n||b.y<0||b.y>=m){
                continue;
            }
            if(map[b.x][b.y] == '#'){
                continue;
            }
            if(map[b.x][b.y]=='@'){
                //flag=1;
                num1 = min(num1,b.num);
                //continue;
                continue;
            }
            if(map[b.x][b.y] == '$'){
                //flag=0;
                num2 = min(num2,b.num);
                continue;
                //continue;
            }
            if(map[b.x][b.y] == '.' && !vis[b.x][b.y]){
                vis[b.x][b.y] = 1;
                q.push(b);
            }

        }
        //if(flag){
            //return;
        //}



    }
}
int main(){

    char s[210];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        //int l = strlen(s);
        for(int j=0;s[j] != '\0';j++){
            map[i][j] = s[j];
            if(map[i][j]=='%'){
                sx = i,sy=j;
            }
        }
    }
    BFS();
    if(num1 < num2)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
