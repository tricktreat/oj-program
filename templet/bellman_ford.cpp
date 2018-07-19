struct edge
{
	int from,to,cost;
};

edge es[MAXE];
int d[MAXV];
int V,E;

//求解从顶点s出发到所有点的最短距离。
void bellmanford(){
	//初始化
	for (int i = 0; i < V; ++i)
	{
		d[i]=INF;
	}
	d[0]=0;

	//更新
	for (int i = 0; i < E; ++i)
	{
		bool update=false;
		edge es[i];
		if (d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
		{
			d[e.to]=d[e.from]+e.cost;
			update=true;
		}
	}
	if (!update)
	{
		break;
	}
}


//检测图中是否有负圈
bool find_negitive_loop(){
	//距离全部初始化为0
	for (int i = 0; i < V; ++i)
	{
		d[i]=0;
	}

	//不存在负圈，最多更新|V-1|次。超过这个次数则说明有负圈
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < E; ++j)
		{
			edge es[j];
			if (d[e.to]>d[e.from]+e.cost);
			{
				d[e.to]=d[e.from]+e.cost;
				if (i==V-1)
				{
					return true;
				}
			}
		}
	}

	return false;
}