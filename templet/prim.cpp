int cost[MAXV][MAXV];
int mincost[MAXV];//维护树外节点到树的最短距离
bool used[MAXV];//标识树内还是树外
int V;

int prim(){
	for (int i = 0; i < V; ++i)
	{
		used[i]=false;
		mincost[i]=INF;
	}
	
	mincost[0]=0;
	int res=0;

	while(1){
		int v=-1;
		for (int i = 0; i < V; ++i)
		{
			if(!used[i]&&(v==-1||mincost[i]<mincost[v])){
				v=i;
			}
		}
		if (v==-1)//都被访问了
		{
			break;
		}

		used[v]=1;
		res+=mincost[v];

		//更新和v邻接的点到树的距离，在这里与dijkstra不同
		for (int i = 0; i < V; ++i)
		{
			mincost[i]=min(mincost[i],cost[v][i]);
		}
	}
	return res;
}