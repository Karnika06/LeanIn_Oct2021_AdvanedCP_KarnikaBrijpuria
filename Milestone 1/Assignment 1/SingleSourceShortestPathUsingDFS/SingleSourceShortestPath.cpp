#include<iostream>
#include<vector>
using namespace std;

void dfs(int n, vector<int> ar[],int v,int visited[],int distance[],int d)
{
	distance[v]=d;
	visited[v]=1;
	for(auto i : ar[v])
	{
		if(visited[i]==0)
			dfs(n, ar, i, visited,distance,d+1);
	}
}

int main()
{
	int m,n,a,b;
	cin>>m>>n;
	vector<int> ar[n+1];
	while(m--)
	{
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int start=2;
	int visited[10],distance[10];
	for(int i=1; i<=n; i++)
	{
		    visited[i] = 0;
		    distance[i]=0;
	}
	int d=0;
	dfs(n,ar,start,visited,distance,d);
	
	
	for(int i=1; i<=n; i++)
	{
		cout<<distance[i]<<" ";
	}
}
