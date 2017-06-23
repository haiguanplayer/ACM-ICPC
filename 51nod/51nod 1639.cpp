#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double res = 1.0;
	for(int i = 2;i <= n;i++)
		res = res*(i-1)*2/((i-1)*2+1);
	cout<<res<<endl;
	return 0;
}