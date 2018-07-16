#include<iostream>
#include<string>

using namespace std;

int n,a;
int count;

void dfs(int i,int a){
	if (a==0)
	{
		count++;
		return;
	}
	if (i>n)
	{
		return;
	}
	for (int j = 0; j <= a/i; ++j)
	{
		dfs(i+1,a-i*j);
	}
}

int main(){
	cin>>n>>a;
	dfs(1,a);
	cout<<count;

	cout<<(-1)%6;
}