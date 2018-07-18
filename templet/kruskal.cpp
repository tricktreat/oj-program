struct edge
{
	int u,v,cost;
};

edge es[MAXE];
int v,e;

bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}

int kruskal(){
	sort(es,es+e,comp);
	init(v);//初始化并查集
	int res=0;
	for (int i = 0; i < e; ++i)
	{
		int u=es[i].u;
		int v=es[i].v;
		if (!same(u,v))
		{
			unite(u,v);
			res+=es[i].cost;
		}
	}
	return res;
}