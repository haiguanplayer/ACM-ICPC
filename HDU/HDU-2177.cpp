/*
������ʯͷ��ÿ��ֻ����һ����ȡ����������ʯͷ������������ȡ��ͬ������ʯͷ�����û��ȡ���䣬
����ȡ���ܷ�ȡʤ��������������һ��ȡ�����������
*/
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b) && (a||b))
    {
        int minn = min(a,b);
        int k = abs(a-b);
        int t = (int)(k*(1.0 + sqrt(5.0))/2.0);
        if(t == minn)
            printf("0\n");
        else
        {
            printf("1\n");
            for(int i = 1;i <= a;i++)
            {
                int p = a-i;
                int q = b-i;
                k = q-p;
                if((int)(k*(1+sqrt(5))/2.0) == p)
                {
                    printf("%d %d\n",p,q);
                }
            }

            for(int i = b-1;i >= 0;i--)
            {
                int p = a;
                int q = i;
                if(p > q)
                    swap(p,q);
                k = q - p;
                if((int)(k*(1+sqrt(5))/2.0) == p)
                {
                    printf("%d %d\n",p,q);
                }
            }
        }
    }
    return 0;
}
