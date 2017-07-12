#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
int n,x;
int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]),sum += a[i];
    if(sum % 10)
        printf("%d\n",sum);
    else{
        sort(a+1,a+1+n);
        for(int i = 1;i <= n;i++){
            if(a[i] % 10 != 0)
                return 0 * printf("%d\n",sum-a[i]);
        }
        printf("0\n");
    }
    return 0;
}
