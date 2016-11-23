//by Rapiz
#include<cstdio>
#include<cstring>
const int N=1e5+10,M=1e9+7;
int ispow(int x){
	int r=0;
	while(x%2==0) x/=2,++r;
	return x==1?r:-1;
}
int a[N],f[N][32];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
        {
			scanf("%d",&a[i]);
			f[i][0]=f[i-1][0]+(a[i]==1);
			f[i][0]%=M;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<32;j++) {
			f[i][j]=f[i-1][j]%M;
			int r=ispow(a[i]);
			if(r==j) f[i][j]+=f[i-1][j-1],f[i][j]%=M;
		}
		int ans=0;
		for(int i=0;i<32;i++) ans=(ans+f[n][i])%M;
		printf("%d\n",ans);
	}
}
