#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
struct node
{
    int val,id;
    bool operator < (const node & p)const
    {
        if(val == p.val)
            return id > p.id;
        return val < p.val;
    }
}a[N];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i].val);
            a[i].id = i;
        }

        sort(a+1,a+1+n);
        int minn = a[1].id;
		int num = 1;
        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
            int temp = 0;
			if(a[i].val > a[num].val)
				temp = a[i].id - minn;
            ans = max(ans ,temp);
			if(minn >= a[i].id)
            {
				num = i;
				minn = a[i].id;
			}
        }
        printf("%d\n",ans);
    }
    return 0;
}
//7 7 3 7 0 3 1 2 7
