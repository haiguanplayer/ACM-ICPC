#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

char str[105];
int main()
{
    while(~scanf("%s",str))
    {
        int len = strlen(str);
        str[len] = str[0];
        int p = 0,sum = 0;
        for(int i = 0;i < len;i++)
        {
            if(str[i] == '0' && str[i+1] == '0')
                p++;
            if(str[i] == '0')
                sum++;
        }
        double a = (double)p / (double)sum;
        double b = (double)sum / (double)len;
        if(fabs(a - b) < 1e-10)
            printf("EQUAL\n");
        else if(a - b > 1e-10)
            printf("SHOOT\n");
        else if(b - a > 1e-10)
            printf("ROTATE\n");
    }
    return 0;
}
