#include<iostream>
#include<cstring>
#define MAXN 17

using namespace std;

int grid[MAXN][MAXN];
int answer[MAXN][MAXN];
int bestanswer[MAXN][MAXN];
int cost,m,n,flag;

int place(int i,int j){
	int sum=0;
	sum+=answer[i-1][j];
	sum+=answer[i][j+1];
	sum+=answer[i][j-1];
    sum+=answer[i][j];
	sum+=grid[i-1][j-1];//answer下边从1开始（默认第0列、第0行为0），grid下标从0开始

	if(sum%2==1){
		return 1;
	}
	return 0;
}

void cacanswer(){//计算2-m行
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			answer[i][j]=place(i-1,j);//根据上一行状态确定下一行
		}
	}
}

int caccost(){
	int sum=0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			sum+=answer[i][j];
		}
	}
	return sum;
}

int isleagle(){
	for (int i = 1; i <= n; ++i)
	{
		if(place(m,i)==1){
			return 0;
		}
	}
	return 1;
}

void dfs(int i){
	if (i>n)
	{
		cacanswer();
		if (!isleagle())
		{
			return;
		}
		flag=1;
		int temp=caccost();
		if (temp<cost)
		{
            for (int i = 1; i <=m; ++i)
            {
                for (int j = 1; j <=n; ++j) {
                    bestanswer[i][j]=answer[i][j];
                }
            }
			cost=temp; 
		}
		return;
	}
	for (int j = 0; j < 2; ++j)
	{
		answer[1][i]=j;
		dfs(i+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);


	while(cin>>m>>n){
		memset(answer,0,sizeof(answer));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>grid[i][j];
			}
		}
		flag=0;
		cost=225;
		dfs(1);
		if (!flag)
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 1;
		}
		for (int i = 1; i <=m; ++i)
		{
			for (int j = 1; j <=n; ++j)
			{
				if (j!=1)
				{
					cout<<" ";
				}
				cout<<bestanswer[i][j];
			}
			cout<<endl;
		}
	}

}