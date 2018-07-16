#include<iostream>
#define MAXN 9

using namespace std;

int n,k,sum=0;
char grid[MAXN][MAXN];

bool canplace(int t,int i){
	if (grid[t][i]=='.')
	{
		return false;
	}
	for (int j = 0; j < t; ++j)
	{
		if (grid[j][i]=='*')
		{
			return false;
		}
	}
	return true;
}

void dfs(int t){
	if (k==0)
	{
		sum++;
		return;
	}
	if (t>=n)
	{
		return;
	}
	for (int i = 0; i < n; ++i)//选择一个合理位置放置
	{
		if(canplace(t,i)){
			k--;
			grid[t][i]='*';//标记
			dfs(t+1);
			k++;
			grid[t][i]='#';//维护状态不变
		}
	}
	dfs(t+1);//均不放置
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>k){
		sum=0;
		if (n==-1&&k==-1)
		{
			break;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>grid[i][j];
			}
		}
		dfs(0);
		cout<<sum<<endl;
	}
}