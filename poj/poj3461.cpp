#include<iostream>
#include<cstring>

#define MAXN 1000005
#define MAXM 10005

using namespace std;

int ne[MAXM];
char des[MAXN];
char pattern[MAXM];
int m;
int n;

void getne(){
	ne[0]=-1;
	int k=-1;
	int j=0;

	while(j<m){
		if (k==-1||pattern[j]==pattern[k])
		{
			ne[++j]=++k;
		}else{
			k=ne[k];
		}
	}
}


int kmpcount(){
	int count=0;
	int i=0,j=0;

	while(i != n && j != m)
	{
		if(des[i] == pattern[j] || j == -1)
			++i, ++j;
		else
			j = ne[j];
		if(j == m)
		{
			count++;
			j = ne[j];
		}
	}
	return count;
}

	

int main(){int t;
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
