#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

#define MAXN 100010

using namespace std;

struct Student
{
	char id[7];
	char name[9];
	int score;
};

bool comp1(const Student& a,const Student& b){
	return strcmp(a.id,b.id)==-1;
}

bool comp2(const Student& a,const Student& b){
	return strcmp(a.id,b.id)==-1;
}

bool comp3(const Student& a,const Student& b){
	return strcmp(a.id,b.id)==-1;
}

Student students[MAXN];

int main(){
	int n,c;
	scanf("%d%d",&a,&b);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %s %d",students[i].id,students[i].name,)
	}
	return 0;
}