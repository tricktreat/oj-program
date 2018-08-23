#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

#define MAXN 30010

struct Stu
{
	char id[15];
	int score;
	int lr;
	int gr;
	int group;

	bool operator<(const Stu& b) const{
		if (score==b.score)
		{
			return strcmp(id,b.id)==-1;
		}else{
			return score>b.score;
		}
	}
};

Stu stu[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	int k=0;
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d",&m);
		for (int j = 0; j < m; ++j)
		{
			scanf("%s %d",stu[k].id,&stu[k].score);
			stu[k].group=i+1;
			k++;
		}
		sort(stu+k-m,stu+k);
		for (int j = 0; j < m; ++j)
		{
			if (j!=0&&stu[k-m+j].score==stu[k-m+j-1].score)
			{
				stu[k-m+j].lr=stu[k-m+j-1].lr;
			}else{
				stu[k-m+j].lr=j+1;
			}
		}
	}

	sort(stu,stu+k);
	for (int j = 0; j < k; ++j)
	{
		if (j!=0&&stu[j].score==stu[j-1].score)
		{
			stu[j].gr=stu[j-1].gr;
		}else{
			stu[j].gr=j+1;
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
	{
		printf("%s %d %d %d\n",stu[i].id,stu[i].gr,stu[i].group,stu[i].lr);
	}
	return 0;
}