#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	vector<int> clds;
	int height;
	node(){
		height=1;
	}
};

node nodes[100];
int level[100]={0};
int n,m,maxlevel=0;;


void input(){
	int child,a,k;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>k;
		for (int j = 0; j < k; ++j)
		{
			cin>>child;
			nodes[a].clds.push_back(child);
	 	}
	}
}

void updateHeight(int nd){
	for (int i = 0; i < nodes[nd].clds.size(); ++i)
	{
		nodes[nodes[nd].clds[i]].height++;
		updateHeight(nodes[nd].clds[i]);
	}
}

void levelLeaves(){
	
	for (int i = 1; i <= n; ++i)
	{
		if (nodes[i].clds.size()==0)
		{
			level[nodes[i].height]++;
			if (nodes[i].height>maxlevel)
			{
				maxlevel=nodes[i].height;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	for (int i = 1; i <= n; ++i)
	{
		updateHeight(i);
	}
	
	levelLeaves();	

	for (int i = 1; i <= maxlevel; ++i)
	{
		cout<<level[i];
		if (i!=maxlevel)
		{
			cout<<" ";
		}
	}

	return 0;
}