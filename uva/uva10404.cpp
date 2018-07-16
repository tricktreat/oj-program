#include<iostream>
#include<cstring>
#define MAXN 1000005
#define MAXC 15

using namespace std;

int d[MAXN];
int choice[MAXC];
int k;

int dp(int i){
	if (d[i]!=-1)
	{
		return d[i];
	}
	d[i]=0;
	for (int j = 0; j < k; ++j)//站在前者的角度，如果k种选择都到达不了每一个为0的阶段（即前者输的阶段）那么当前阶段也是输
	{
		if (i>=choice[j]&&!dp(i-choice[j])) //如果choice包括1,3,8，0:后者胜，1：前者胜，2:后者胜，3:前者胜...
		{
			d[i]=1;
		}
	}
	return d[i];
}

int main(){
	int n;
	while(cin>>n>>k){
		memset(d,-1,sizeof(d));
		for (int i = 0; i < k; ++i)
		{
			cin>>choice[i];
		}
		if (dp(n))
		{
			cout<<"Stan wins"<<endl;
		}else{
			cout<<"Ollie wins"<<endl;

		}
	}
}

// #include <cstdio>
// #include <cstring>
// #include <algorithm>
//
// using namespace std;
// const int N = 10000005;
// const int M = 10;
 
// int v[M];
// int dp[N];
 
// int main () {
 
// 	int n, m;
// 	while (scanf ("%d%d", &n, &m) != EOF ) {
 
// 		for (int i = 0; i < m; i++)
// 			scanf ("%d", &v[i]);
 
// 		sort (v, v + m);
// 		memset (dp, 0, sizeof (dp));   //因为只有赋值为1的情况，那么就可以让这些值初始为0，如果后面判断所有的d【j- v【i】】 ！= 0 那么就是ollie获胜，就不用再赋值为0。
 
// 		for (int i = 1; i <= n; i++)   //保证前面小的dp【i】值先确定。
// 			for (int j = 0; j < m; j++) {
 
// 				if (i >= v[j] && dp[i - v[j]] == 0)
// 					dp[i] = 1;
// 			}
 
	
// 		printf ("%s wins\n", dp[n] ? "Stan": "Ollie");
// 	}
// 	return 0;
// }
