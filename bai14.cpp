#include<bits/stdc++.h>
using namespace std;
vector<int> v(1001,0);
vector<vector<int> > matrix(1001,vector<int>(1001,INT_MAX));
vector<int> currentTime(1001,INT_MAX);
vector<int> maxValue(1001,0);
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>v[i];
	}
	int m;
	cin>>m;
	for(int i =1; i<=m;i++){
		int p,q,u;
		cin>>p>>q>>u;
		matrix[p][q]=u;
		matrix[q][p]=u;
	}
	pq.push({0,1});
	maxValue[1]=v[1];
	currentTime[1]=0;
	while(!pq.empty()){
		int value = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();
		for(int i=1; i<=n;i++){
			if(matrix[currentNode][i]!=INT_MAX){
				if(currentTime[currentNode]+matrix[currentNode][i]<currentTime[i]){
					currentTime[i]= currentTime[currentNode]+matrix[currentNode][i];
					maxValue[i]= maxValue[currentNode]+v[i];
					pq.push({currentTime[i],i});
				}
				else if(currentTime[currentNode]+ matrix[currentNode][i]==currentTime[i]&&maxValue[i]<maxValue[currentNode]+ v[i]){
					maxValue[i]=maxValue[currentNode]+v[i];
					
				}
			}
		}
		
	}
	cout<<maxValue[n];
	
}
