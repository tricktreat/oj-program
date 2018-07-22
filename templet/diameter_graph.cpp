#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 10010
using namespace std;

struct edge
{
	int to,cost;
};

vector<edge> G[MAXN];
int n;
int maxl;
int visited[MAXN];
int node;
int depth[MAXN];//bfs记录层数（路径长度）

void dfs(int i,int depth){
	visited[i]=1;
	for (int j = 0; j < G[i].size(); ++j)
	{
		int v=G[i][j].to;
		if (!visited[v])
		{
			if (G[i][j].cost+depth>maxl)
			{
				maxl=G[i][j].cost+depth;
				node=v;
			}
			dfs(v,depth+G[i][j].cost);
		}
	}
}

void bfs(int i){
	queue<int> q;
	q.push(i);
	visited[i]=1;
	
	depth[i]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for (int k = 0; k < G[u].size(); ++k)
		{
			int v=G[u][k].to;
			if (!visited[v])
			{
				depth[v]=depth[u]+G[u][k].cost;
				if (maxl<depth[v])
				{
					maxl=depth[v];
					node=v;
				}
				q.push(v);
				visited[v]=1;
			}
		}
	} 
}

int main(){
	edge e;
	int from,to,cost;
	
	while(cin>>from>>to>>cost){
		e.cost=cost;

		e.to=to;
		G[from].push_back(e);

		e.to=from;
		G[to].push_back(e);
		n=max(n,from);
		n=max(n,to);
	}
	//dfs(1,0);
	bfs(1);
	memset(visited,0,sizeof(visited));
	maxl=0;
	//dfs(node,0);
	bfs(node);
	cout<<maxl<<endl;
}
