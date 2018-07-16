#include<iostream>
#include<cstring>

#define MAXN 1000005
#define MAXM 10005

using namespace std;

int ne[MAXM];
char des[MAXM];
char pattern[MAXN];
int m;
int n;

void getne(){
	ne[0]=-1;
	int k=-1;
	int j=0;

	while(j<m){
		if (k==-1||des[j]==pattern[j])
		{
			ne[++j]=++k;
		}else{
			k=ne[k];
		}
	}
}

int kmpcount(){
	if (m==1&&n==1)
	{
		if (des[0]==pattern[0])
		{
			return 1;
		}else{
			return 0;
		}
	}
	int count=0;

	int i=0,j=0;

	for (; i < n; ++i)
	{
		while(j>0&&des[i]!=pattern[j]){
			j=ne[j];
		}
		if (des[i]==pattern[j])
		{
			j++;
		}
		if (j==m)
		{
			count++;
			j=ne[j];
		}
	}
	return count;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>pattern;
		cin>>des;

		m=strlen(pattern);
		n=strlen(des);

		getne();

		cout<<kmpcount()<<endl;
	}
}