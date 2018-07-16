#include<iostream>
#include<queue>
#include<cstring>

#define MAXN 100005
using namespace std;

int s,e;
int visited[MAXN];
queue<int> q;

int bfs(){
	q.push(s);
	visited[s]=1;
	int step=0;
	int last=s;
	int m,n;
	while(!q.empty()){
		m=q.front();
		q.pop();
		if(m==e){
			return step;
		}
		if (((m+1)<=e)&&visited[m+1]==0)
		{
			q.push(m+1);
			visited[m+1]=1;
			n=m+1;
		}
		if (((m-1)>=0)&&visited[m-1]==0)
		{
			q.push(m-1);
			visited[m-1]=1;
			n=m-1;
		}		
		if (((2*m)<=MAXN)&&visited[2*m]==0)//这里不能是与e比较
		{
			q.push(2*m);
			visited[2*m]=1;
			n=2*m;
		}

		if(m==last){//使用结构体记录遍历的层数，或者使用标记值记录当前层结束的节点
			step++;
			last=n;
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin>>s>>e){
		memset(visited,0,sizeof(visited));
		while(!q.empty()){
			q.pop();
		}
		cout<<bfs()<<endl;
	}
	return 0;
}

//
// #include<iostream>  
// #include<queue>  
// #include<cstring>  
// #include<cstdio>  
// using namespace std;  
  
// const int maxn=100001;  
  
// bool vis[maxn];//标记数组  
// int step[maxn];//记录到了每一位置所走的步数  
// queue <int> q;//定义队列  
  
// int bfs(int n,int k)  
// {  
//     int head,next;  
//     q.push(n);   //开始FJ在n位置，n入队  
//     step[n]=0;  
//     vis[n]=true; //标记已访问  
//     while(!q.empty())  //当队列非空  
//     {  
//         head=q.front();  //取队首  
//         q.pop();         //弹出对首  
//         for(int i=0;i<3;i++)     //FJ的三种走法  
//         {  
//             if(i==0) next=head-1;  
//             else if(i==1) next=head+1;  
//             else next=head*2;  
//             if(next<0 || next>=maxn) continue; //排除出界情况  
//             if(!vis[next])  //如果next位置未被访问  
//             {  
//                 q.push(next);    //入队  
//                 step[next]=step[head]+1;  //步数+1  
//                 vis[next]=true;  //标记已访问  
//             }  
//             if(next==k) return step[next];  //当遍历到结果，返回步数  
//         }  
//     }  
// }  
// int main()  
// {  
//     int n,k;  
//     while(cin>>n>>k)  
//     {  
//         memset(step,0,sizeof(step));  
//         memset(vis,false,sizeof(vis));  
          
//         while(!q.empty()) q.pop(); //注意调用前要先清空  
//         if(n>=k) printf("%d\n",n-k);  
//         else printf("%d\n",bfs(n,k));  
//     }  
//     return 0;  
// }  