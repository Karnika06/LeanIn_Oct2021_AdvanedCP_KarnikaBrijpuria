// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool dfs(vector<int> ar[],int v,int visited[],int c,int color[])
{
	
	visited[v]=1;
	color[v]=c;
	for(int i : ar[v])
	{
		if(visited[i]==0)
		{
			bool res = dfs(ar,i,visited,c^1, color);
			if(res ==false)
				return false;
		}
		else
		if(color[i] == color[v])
		return false;
	}
	return true;
	
}
	
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    int visited[100001],color[100001];
	for(int i=0; i<V; i++)      
		    visited[i] = 0, color[i]=0;
	
	bool flag = true;
	for(int i=0; i<V; i++)
	{
		if(visited[i]==0)
		{
			int res = dfs(adj,i,visited,0,color);
			if(res == false)
			flag = false;
		}
	}
	return flag;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends