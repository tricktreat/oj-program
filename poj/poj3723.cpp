#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXR 50010
#define MAXV 20010

using namespace std;

typedef long long ll;

struct edge
{
	int u,v,cost;
};

edge edges[MAXR];
int r,V;
int par[MAXV];
int height[MAXV];

void init(int n){
	for (int i = 0; i < n; ++i)
	{
		par[i]=i;
		height[i]=0;
	}
}

int find(int x){
	if (x==par[x])
	{
		return x;
	}else{
		return par[x]=find(par[x]);//路径压缩
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if (height[x]>height[y])
	{
		par[y]=x;
	}else if(height[x]<height[y]){
		par[x]=y;
	}else{
		par[y]=x;
		height[x]++;
	}
}

bool cmp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}

ll kruskal(){
	init(V);
	sort(edges,edges+r,cmp);
	ll res=0;
	for (int i = 0; i < r; ++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		if (!same(u,v))
		{
			unite(u,v);
			res+=edges[i].cost;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int n,m;
		cin>>n>>m>>r;
		V=n+m;
		for (int j = 0; j < r; ++j)
		{
			scanf("%d%d%d",&edges[j].u,&edges[j].v,&edges[j].cost);
			//cin>>edges[j].u>>edges[j].v>>edges[j].cost;
            edges[j].v+=n;
            edges[j].cost=- edges[j].cost;
		}
		cout<<V*10000+kruskal()<<'\n';
	}
}