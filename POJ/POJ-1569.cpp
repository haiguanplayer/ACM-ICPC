/*
题目大意：平面上有一些点（很少），求以这些点为顶点
的三角形中，内部无其他点的面积最大的三角形是哪个
*/
#include <iostream>
#include<cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
struct Point
{
    double x,y;
    string name;
};
Point ps[25];

double Area(int i,int j,int k)
{
    return fabs((ps[k].y-ps[i].y)*(ps[j].x-ps[i].x)-(ps[j].y-ps[i].y)*(ps[k].x-ps[i].x));
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int Msum = 0;
        int a,b,c;
        for(int i = 1;i <= n;i++)
        {
            cin >> ps[i].name;
            cin >>ps[i].x >> ps[i].y;
            //scanf("%lf%lf",&,&);
        }
            //printf("11\n");
        for(int i = 1;i <= n-2;i++)
            for(int j = i+1;j <= n-1;j++)
                for(int k = j+1;k <= n;k++)//
                {

                    //if(i==j || i==k || j==k)
                        //continue;
                    int flag=1;
                    int temp=Area(i,j,k);
                    for(int t=0;t<n;t++)
                    {
                        if(t!=i&&t!=j&&t!=k)
                        {
                            if(temp==(Area(t,i,j)+Area(t,j,k)+Area(t,k,i)))
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    if(flag&&temp>Msum)
                    {

                            Msum=temp;
                            a=i;
                            b=j;
                            c=k;

                    }
                }
          cout<<ps[a].name<<ps[b].name<<ps[c].name<<endl;
    }
    return 0;
}
