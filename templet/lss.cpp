int matrix[MAXN][MAXN];
int dp[MAXN];
int arr[MAXN];
int n;
int col_start,col_end,row_start,row_end;
int temp_s,temp_e;

//一维
int lss(){
	dp[0]=arr[0];
	int maxv=0;
	int tmp_start=0;
	
	for (int i = 1; i < n; ++i)
	{
		if (dp[i-1]>0)
		{
			dp[i]=dp[i-1]+arr[i];
		}else{
			dp[i]=arr[i];
			tmp_start=i;
		}
		if (dp[i]>maxv)
		{
			maxv=dp[i];
			temp_s=tmp_start;
			temp_e=i;
		}
	}
	return maxv;
}

//二维
int lss2(){
	int maxv=0;

	for (int i = 0; i < n; ++i)//行号起点
	{
		memset(arr,0,sizeof(arr));

		for (int j = i; j < n; ++j)//行号终点
		{
			for (int k = 0; k < n; ++k)
			{
				arr[k]+=matrix[j][k];//累加
			}
			int tmp=lss();
			if (maxv<tmp)
			{
				maxv=tmp;
				row_end=j;
				row_start=i;
				col_start=temp_s;
				col_end=temp_e;
			}
		}
	}
	return maxv;
}