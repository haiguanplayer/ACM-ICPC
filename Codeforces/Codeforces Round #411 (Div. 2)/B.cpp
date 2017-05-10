#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    //int a = 0,b = 0;
    for(int i = 0;i < n;i++)
    {
        if(i %4 == 0)
        {
            putchar('a');
        }
        else if(i % 4 == 1)
        {
            putchar('a');
        }
        else if(i % 4 == 2)
            putchar('b');
        else if(i % 4 == 3)
            putchar('b');
    }
    putchar('\n');
    return 0;
}
//aabb
