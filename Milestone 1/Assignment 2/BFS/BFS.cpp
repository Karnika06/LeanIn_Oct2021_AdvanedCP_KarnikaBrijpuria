
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void bfs(int v, vector<int> ar[], int visited[], vector<int> &ans)
    {
	visited[v]=1;
	//dist[v] = 0;
	queue<int> q;
	q.push(v);
	ans.push_back(v);
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int i : ar[curr])
		{
		
		if(visited[i] == 0)
		{
			q.push(i);
			ans.push_back(i);
			//dist[i] = dist[curr] + 1;
			visited[i] =1;
		}
	}
}
}
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[10001];
	vector<int> ans;
	for(int i=0; i<V; i++)      //mark all vertices unvisited 
		    visited[i] = 0;
        bfs(0, adj, visited, ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends