#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 1010

using namespace std;

int n,m;
int fa[MAXN];
int height[MAXN];
int degree[MAXN];

void init(){
    for (int i = 0; i < n; ++i) {
        fa[i]=i;
        height[i]=0;
    }
}

int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}

void merge(int x,int y){
    x=fa[x];
    y=fa[y];
    if(x==y){
        return;
    }
    if(height[x]>height[y]){
        fa[y]=x;
    }else{
        fa[x]=y;
        if(height[x]==height[y]){
            height[y]++;
        }
    }
}

int main(){
    while(cin>>n&&n!=0&&cin>>m&&m!=0 ){
        init();
        memset(degree,0, sizeof(degree));
        for (int i = 0; i < m; ++i) {
            int f,t;
            cin>>f>>t;
            degree[f]++;
            degree[t]++;
            merge(f,t);
        }
        int flag=0,cnt=0;
        for (int i = 0; i < n; ++i) {
            if(fa[i]==i){
                cnt++;
            }
            if(degree[i]%2!=0) {
                flag = 1;
            }
        }
        if(cnt==1&&flag==0){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
}