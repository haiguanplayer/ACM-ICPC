/*
����һ��Nim״̬���൱�ں�N��ʯͷ���������м��ַ�����ͨ������ĳ
һ��ʯͷ��״̬��ֻ׼ȡ������ʹ�µ�Nim״̬Ϊ�ذ�̬��
������˵���������Nim��Ϸ״̬�ж����ַ����ܹ�Ӯ��
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1005];
int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            ans ^= a[i];
        }
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if((ans ^ a[i]) < a[i])
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
