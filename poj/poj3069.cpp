#include<iostream>
#include<cstring>
#include<algorithm>

#define MAXN 1010

using namespace std;

int r,n;
int points[MAXN];

int main(){
	while(cin>>r>>n&&r!=-1&&n!=-1){
		int count=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>points[i];
		}
		sort(points,points+n);
		int i=0;
		while(i<n){
			int s=points[i++];
			while(i<n&&points[i]<=s+r){
				i++;
			}
			int p=points[i-1];
			while(i<n&&points[i]<=p+r){
				i++;
			}
			count++;
		}
		cout<<count<<endl;
	}
}
