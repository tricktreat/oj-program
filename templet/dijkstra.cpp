int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
int V;

//邻接矩阵+一般实现
void djikstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	d[s]=0;

	while(true){
		int v=-1;
		for (int i = 0; i < V; ++i)
		{
			if (!used[i]&&(v==-1||d[i]<d[v]))
			{
				v=i;
			}
		}
		if (v!=-1)
		{
			used[v]=1;
		}else{
			break;
		}

		for (int i = 0; i < V; ++i)
		{
			d[i]=min(d[i],d[i]+cost[v][i]);
		}
	}
}

//邻接表+堆
struct edge{
	int to,cost;
}

typedef pair<int,int> P;

int V;
vector<edge> G[MAXV];
int d[MAXV];

void djikstra(){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que. ();
		int v=p.second;
		if (d[v]<p.first)
		{
			continue;
		}
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e=G[v][i];
			if (d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	} 
}
