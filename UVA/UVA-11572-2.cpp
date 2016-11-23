#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

const int N = 1e6 + 5;
int A[N],last[N];
map<int,int> cur;
int main()
{
    int t ,n;
    cin >> t;
    while(t--)
    {
        cur.clear();
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&A[i]);
            if(!cur.count(A[i]))
                last[i] = -1;
            else
                last[i] = cur[A[i]];
            cur[A[i]] = i;
        }

        int L = 1,R = 1,maxn = 0;
        while(R <= n)
        {
            while(R <= n && last[R] < L)
                R++;
            maxn = max(maxn,R-L);
            L++;
        }
        printf("%d\n",maxn);
    }
    return 0;
}

