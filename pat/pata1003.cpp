#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define INF 0x3fffffff
#define MAXN 504
using namespace std;

int G[MAXN][MAXN];
int dist[MAXN];
int team[MAXN];
int visit[MAXN];
vector<int> pre[MAXN];
int v,e,src,des,maxcost,cnt;
vector<int> path;

void init(){
	fill(dist,dist+MAXN,INF);
	fill(G[0],G[0]+MAXN*MAXN,INF);
}

int findMin(){

	int minv=INF;
	int mini=-1;
	for (int i = 0; i < v; ++i)
	{
		if (visit[i]==0&&dist[i]<minv)
		{
			minv=dist[i];
			mini=i;
		}
	}
	return mini;
}

void djisktra(){
	dist[src]=0;

	int m;
	while((m=findMin())!=-1){
		visit[m]=1;
		for (int i = 0; i < v; ++i)
		{
			if (G[m][i]!=INF&&visit[i]==0)
			{
				if (dist[i]>(dist[m]+G[m][i]))
				{
					dist[i]=(dist[m]+G[m][i]);
					pre[i].clear();
					pre[i].push_back(m);
				}else if(dist[i]==(dist[m]+G[m][i])){
					pre[i].push_back(m);
				}
			}
		}
	}
}

void calCost(){
	int sum=0;

	for (int i = 0; i < path.size(); ++i)
	{
		sum+=team[path[i]];
	}
	if (sum>maxcost)
	{
		maxcost=sum;
	}
}

void dfs(int des){
	if (des==src)
	{
		path.push_back(des);
		calCost();
		cnt++;
		path.pop_back();
		return;
	}
	path.push_back(des);
	for (int i = 0; i < pre[des].size(); ++i)
	{
		dfs(pre[des][i]);
	}
	path.pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	int a,b,c;
	cin>>v>>e>>src>>des;

	for (int i = 0; i < v; ++i)
	{
		cin>>team[i];
	}

	for (int i = 0; i < e; ++i)
	{
		cin>>a>>b>>c;
		G[a][b]=G[b][a]=c;
	}

	djisktra();

	dfs(des);

	cout<<cnt<<" "<<maxcost;
}