int par[MAXN];
int rank[MAXN];

//初始化
void init(int n){
	for (int i = 0; i < n; ++i)
	{
		par[i]=i;
		rank[i]=0;
	}
}

//查询树的根，并进行路径压缩。
void find(int x){
	if (par[x]==x)
	{
		return x;
	}else{
		return par[x]=find(par[x]);//路径压缩
	}
}

//合并x和y所属集合
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if (x==y)
	{
		return;
	}

	if (rank[x]>rank[y])
	{
		par[y]=x;
	}else{
		par[x]=y;
		if (rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

//判断x和y是否属于同一个集合
bool same(int x,int y){
	return find(x)==find(y);
}