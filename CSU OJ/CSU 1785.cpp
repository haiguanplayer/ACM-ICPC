#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;

int main()
{
    int T,Case= 1;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int a = n/1000;
        int b = (n/100)%10;
        int c = (n/10)%10;
        int d = n%10;
        int term ;
        int cnt = 0;
        for(int i=1;i<=9;i++){
            if(i== a){
                continue;
            }
            term = i*1000+b*100+c*10+d;
            if(term == (int )sqrt(term) * (int)sqrt(term)){
                cnt++;
                //cout <<term<<endl;
            }
        }
        for(int j=0;j<=9;j++){
             if(j== b){
                continue;
            }
            term = a*1000+j*100+c*10+d;
            if(term == (int )sqrt(term) * (int)sqrt(term)){
                cnt++;
                //cout <<term<<endl;
            }
        }
        for(int k = 0;k<=9;k++){
            if(k== c){
                continue;
            }
            term = a*1000+b*100+k*10+d;
            if(term == (int )sqrt(term) * (int)sqrt(term)){
                cnt++;
                //cout <<term<<endl;
            }
        }
        for(int l=0;l<=9;l++){
            if(l== d){
                continue;
            }
            term = a*1000+b*100+c*10+l;
            if(term == (int )sqrt(term) * (int)sqrt(term)){
                cnt++;
                //cout <<term<<endl;
            }
        }
        printf("Case %d: %d\n",Case++,cnt);
    }
    return 0;
}
