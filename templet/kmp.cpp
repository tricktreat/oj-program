int pattern[MAXL];
int des[MAXL];
int n;
int m;
int ne[MAXL];

void getNext(){
	int k=-1;
	int j=0;
	ne[j]=k;

	while(j<m){
		if (k==-1||pattern[j]==pattern[k])
		{
			ne[++k]=++j;
		}else{
			k=ne[k];
		}
	}
}

int kmp(){
	int i=0;
	int j=0;

	while(i<n){
		if (j==-1||des[i]==pattern[j])
		{
			j++;
			i++;
		}else{
			j=ne[i];
		}

		if (j==m)
		{
			return i-j+1;
		}
	}
	return -1;
}