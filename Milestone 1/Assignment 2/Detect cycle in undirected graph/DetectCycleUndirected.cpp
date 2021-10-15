// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int n, vector<int> ar[],int v,int visited[],int parent)
{
	//cout<<parent<<endl;
	visited[v]=1;
	for(int i : ar[v])
	{
		if(visited[i]==0)
		{
			bool res = dfs(n,ar,i,visited,v);
			if(res ==true)
				return true;
		}
		else
		if(parent != i)
		return true;
	}
	return false;
	
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[100001];
	for(int i=0; i<V; i++)      
		    visited[i] = 0;
	
	bool res ,flag = false;
	for(int i=0; i<V; i++)
	{
		if(visited[i]==0)
		{
			res = dfs(V,adj,i,visited,-1);
			if(res == true)
			{
			flag = true;
			break;
		}
			

		}
	}
	return flag;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends