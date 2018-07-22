typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A,mat &B){
	mat c(A.size,vec(B[0].size()));//向量的双参数构造函数，第二个参数表示元素默认值
	for (int i = 0; i < A.size(); ++i)
	{
		for (int k = 0; k < B.size(); ++k)
		{
			for (int j = 0; j < B[0].size(); ++j)
			{
				c[i][j]=A[i][k]*B[k][j]+c[i][j];
			}
		}
	}
	return c;
}

mat fast_matrix_pow(mat &A,int n){
	mat B(A.size(),vec(A.size()));

	//构造单位矩阵
	for (int i = 0; i < A.size(); ++i)
	{
		B[i][i]=1;
	}

	while(n>0){
		if (n&1)
		{
			B=mul(B,A),
		}
		B=mul(A,A);
		n>>1;
	}

	return B;
}