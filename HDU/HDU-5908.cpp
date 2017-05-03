Abelian Period
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 262144/131072 K (Java/Others)
Total Submission(s): 883    Accepted Submission(s): 356


Problem Description
Let S be a number string, and occ(S,x) means the times that number x occurs in S.

i.e. S=(1,2,2,1,3),occ(S,1)=2,occ(S,2)=2,occ(S,3)=1.

String u,w are matched if for each number i, occ(u,i)=occ(w,i) always holds.

i.e. (1,2,2,1,3)≈(1,3,2,1,2).

Let S be a string. An integer k is a full Abelian period of S if S can be partitioned into several continous substrings of length k, and all of these substrings are matched with each other.

Now given a string S, please find all of the numbers k that k is a full Abelian period of S.


Input
The first line of the input contains an integer T(1≤T≤10), denoting the number of test cases.

In each test case, the first line of the input contains an integer n(n≤100000), denoting the length of the string.

The second line of the input contains n integers S1,S2,S3,...,Sn(1≤Si≤n), denoting the elements of the string.


Output
For each test case, print a line with several integers, denoting all of the number k. You should print them in increasing order.


Sample Input

2
6
5 4 4 4 5 4
8
6 5 6 5 6 5 5 6



Sample Output

3 6
2 4 8



Source
BestCoder Round #88

关键是
挺巧妙的暴力

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 100005;
int s[N],sum[N],pos[N];
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&s[i]);

        int num = 0;

        for(int i = 1;i <= n;i++)
        {
            if(n % i == 0)//i != 1 &&
            {
                int cnt = 1;
                bool flag = true;
                while(cnt < n/i)
                {
                    for(int j = 1;j <= i;j++)//第一段，不过每次都来，浪费啊，但这样简便
                        sum[s[j]]++;

                    for(int j = cnt*i+1;j <= i*(cnt+1);j++)
                        if(sum[s[j]])//前面有的才需要这个
                            sum[s[j]]--;

                    for(int j = 1;j <= i;j++)
                    {
                        if(sum[s[j]] != 0)
                        {
                            sum[s[j]] = 0;//恢复0
                            flag = false;
                        }
                    }
                    if(!flag)//这个i不符合
                        break;
                    cnt++;//符合的话，枚举下一段
                }
                if(flag)//符合的话
                    pos[num++] = i;
            }
        }

        for(int i = 0;i < num-1;i++)
            printf("%d ",pos[i]);
        printf("%d\n",pos[num-1]);
    }
    return 0;
}



