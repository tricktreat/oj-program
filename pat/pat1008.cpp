#include<iostream>
#define MAXN 105

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,floor[MAXN];
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>floor[i];
	}
	int sum=floor[0]*6+n*5;
	for (int i = 1; i < n; ++i)
	{
		sum+=(floor[i]>floor[i-1]?(floor[i]-floor[i-1])*6:(floor[i-1]-floor[i])*4);
	}
	cout<<sum;

}