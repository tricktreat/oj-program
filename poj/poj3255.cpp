#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#define INF 1<<30
#define MAXN 5010

using namespace std;

struct edge
{
	int to,cost;
};

typedef pair<int,int> P;
 
int n,r;
vector<edge> G[MAXN];  //邻接表表示，点对应出边（edge保存出点和）
int dist[MAXN];
int dist2[MAXN];

void dijkstra_2(){
	priority_queue<P,vector<P>,greater<P> > que; 
	fill(dist,dist+n,INF);
	fill(dist2,dist2+n,INF);
	dist[0]=0;
	que.push(P(0,0));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int u=p.second;
		if (p.first>dist2[u])//优先队列的更新是直接插入，所以这里需要判断，把不是最短和次短的过滤掉
		{
			continue;
		}
		for (int i = 0; i < G[u].size(); ++i)
		{
			int v=G[u][i].to;
			int c=G[u][i].cost;
			int d=p.first+c;//错误->int d=dist[u]+c。这里一定是p.first，可能是最短也可能是次短
			if (dist[v]>d)
			{
				swap(dist[v],d);
				que.push(P(dist[v],v));
			}

			if (dist2[v]>d&&d>dist[v])//次短距离要么是最短距离+cost，要么是次短距离加上cost
			{
				dist2[v]=d;
				que.push(P(dist2[v],v));
			}
		}
	}
}

int main(){
	while(cin>>n>>r){
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < r; ++i)
		{
			int v1,v2;
			edge e;
			cin>>v1>>v2>>e.cost;
			v1--;
			v2--;
			e.to=v1;
			G[v2].push_back(e);
			e.to=v2;
			G[v1].push_back(e);
		}

		dijkstra_2();
		cout<<dist2[n-1]<<endl;
	}
}