


//之前需要根据节点之间的关系，构造dag邻接矩阵。比如矩形嵌套，大小关系比较，砖块颜色匹配堆叠等
//其实lis就是隐式的dag问题，只不过没有显式的构造邻接矩阵，直接在dp中关系进行比较。
void printdag(int i){
	for (int j = 0; j < m; ++j)
	{
		if (adj[i][j]==1&&d[i]==d[j]+1)//这两个条件缺一不可
		{
			printdag(j);
			break;
		}
	}
	if (d[i]!=1)
	{
		cout<<" ";
	}
	cout<<i+1;
}

int dp(int i){
	if(d[i]>0){
		return d[i];
	}
	d[i]=1;//终结点，出度为零直接返回1
	for (int j = 0; j < m; ++j)
	{
		if (adj[i][j])
		{
			d[i]=max(d[i],dp(j)+1);
		}
	}
	return d[i];
}
