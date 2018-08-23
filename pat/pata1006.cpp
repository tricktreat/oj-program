#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

struct record
{
	char id[16];
	int start;
	int end;
	record(char* m_id,int m_start,int m_end){
		strcpy(id,m_id);
		start=m_start;
		end=m_end;
	}
};

vector<record> records;

int main(){
	 ios::sync_with_stdio(false);
	 cin.tie(0);

	 int n,h,m,s,start,end;
	 char id[16],st[10],et[10];
	 cin>>n;

	 for (int i = 0; i < n; ++i)
	 {
	 	cin>>id>>st>>et;
	 	sscanf(st,"%d:%d:%d",&h,&m,&s);
		 start=h*3600+m*60+s;

		 sscanf(et,"%d:%d:%d",&h,&m,&s);
		 end=h*3600+m*60+s;
		 records.push_back(record(id,start,end));
	 }

	 int mins=24*3600,maxe=0;
	 char minid[16],maxid[16];
	 for (vector<record>::iterator it=records.begin();it!=records.end();it++){
	 	if(it->start<mins){
	 		mins=it->start;
	 		strcpy(minid,it->id);
	 	}
	 	if(it->end>maxe){
	 		maxe=it->end;
	 		strcpy(maxid,it->id);
	 	}
	 }
	 cout<<minid<<" "<<maxid;
}