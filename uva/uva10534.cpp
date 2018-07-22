#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

#define MAXN 10000

using namespace std;

int n,seq[MAXN];
int decs[MAXN];
int inc[MAXN];
vector<int> v(MAXN);
vector <int>::iterator it;

// void lis(){
// 	inc[0]=1;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		inc[i]=1;
// 		for (int j = 0; j < i; ++j)
// 		{
// 			if (seq[i]>seq[j])
// 			{
// 				inc[i]=max(inc[i],inc[j]+1);
// 			}
// 		}
// 	}
// }

// void lds(){
// 	decs[n-1]=1;
// 	for (int i = n-2; i > 0; --i)
// 	{
// 		decs[i]=1;
// 		for (int j = i+1; j < n; ++j)
// 		{
// 			if (seq[j]<seq[i])
// 			{
// 				decs[i]=max(decs[i],decs[j]+1);
// 			}
// 		}
// 	}
// }

void lis(){
	v.clear();
	v.push_back(seq[0]);
	inc[0]=1;
	for (int i = 1; i < n; ++i)
	{
		if (seq[i]>v[v.size()-1])
		{
			v.push_back(seq[i]);
		}else{
			it=lower_bound(v.begin(),v.end(),seq[i]);
			*it=seq[i];
		}
		inc[i]=v.size();
	}
}

void lds(){
	v.clear();
	v.push_back(seq[n-1]);
	decs[n-1]=1;
	for (int i = n-2; i >=0; --i)
	{
		if (seq[i]>v[v.size()-1])
		{
			v.push_back(seq[i]);
		}else{
			it=lower_bound(v.begin(),v.end(),seq[i]);
			*it=seq[i];
		}
		decs[i]=v.size();
	}
}

int main(){
	while(cin>>n){
		for (int i = 0; i < n; ++i)
		{
			cin>>seq[i];
		}
		lis();
		lds();
		int maxl=0;
		for (int i = 0; i < n; ++i)
		{
			maxl=max(maxl,min(decs[i],inc[i])*2-1);
		}
		cout<<maxl<<endl;
	}
}