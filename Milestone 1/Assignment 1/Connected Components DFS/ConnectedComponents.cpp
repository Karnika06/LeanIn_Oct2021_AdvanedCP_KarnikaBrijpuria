#include<iostream>
#include<vector>
using namespace std;

class ConnectedComponents
{
	public :
	void dfs(int n, vector<int> ar[] , int v, int visited[])
	{
		visited[v] = 1;
		for(auto i : ar[v])
		{
			if(visited[i]==0)
			dfs(n,ar,i,visited);
		}
	}	
	
	int cc(int n, vector<int> ar[])
	{
		int count=0;
		int visited[20];
		for(int i=1; i<=n; i++)      //mark all vertices unvisited 
		    visited[i] = 0;
		    
		for(int i = 1; i<n; i++)
		{
			if(visited[i] == 0)
			{
			dfs(n, ar, i, visited);
			count++;
			}
		}
		return count;
	}
};

int main()
{
	int n,e,a,b;
	ConnectedComponents obj;
	cout<<endl<<"Enter no. of vertices and edges: ";
	cin>>n>>e;
	cout<<endl<<"Enter vertices of edges: ";
	vector<int> ar[n+1];
	while(e--)
	{
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	
	cout<<"Connected component: "<<obj.cc(n,ar);
}
