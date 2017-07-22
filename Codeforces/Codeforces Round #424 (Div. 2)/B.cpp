#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
char s1[N],s2[N],str[N];
char a[155];

int main()
{
	cin >> s1 >> s2 >> str;
	for(int i = 0;i < 26;i++)
		a[s1[i]] = s2[i];
	for(int i = 0;str[i] != '\0';i++)
		if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = a[str[i]];
        else if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = a[str[i]+32]-32;
	cout << str << endl;
	return 0;
}
