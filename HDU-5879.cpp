/*
����Ҫ֪����1/(i*i)�м��ޣ����Լ��㵽һ����ֵ�Ժ����᲻�ٱ仯��С������5λ����
Ȼ���ҵ�1e6��ע��1M�����롣ans atoi()

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char str[10000005];
int main()
{
    while(~scanf("%s",str))
    {
        int len = strlen(str);
        double tosum = 0;
        if(len <= 6)
        {
            if(len < 6 || str[0] == '1')
            {
                int n = atoi(str);
                for(int i = 1;i <= n;i++)
                {
                    double tmp = i;
                    tosum += 1/(tmp*tmp);
                }
                printf("%.5f\n",tosum);
            }
            else
                printf("1.64493\n");
         }
         else if(len > 6)
                printf("1.64493\n");
    }
    return 0;
}
