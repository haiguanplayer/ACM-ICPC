#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int N = 1e6 + 5;
int A[N];
int main()
{
    int t ,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&A[i]);
        set<int> s;
        int L = 1,R = 1,maxn = 0;
        while(R <= n)
        {
            while(R <= n && !s.count(A[R]))
                s.insert(A[R++]);
            maxn = max(maxn,R-L);
            s.erase(A[L++]);
        }
        printf("%d\n",maxn);
    }
    return 0;
}
