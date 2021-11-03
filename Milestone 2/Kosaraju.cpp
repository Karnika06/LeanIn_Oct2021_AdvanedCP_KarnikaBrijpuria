#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
    void dfs(vector<int> adj[],int v,vector<int>&vis, stack<int>&s) // Topo sort of graph
	{
	    vis[v]=1;
	    
	    for(auto i:adj[v])
	        if(!vis[i])
	            dfs(adj,i,vis,s);
	    
	    s.push(v);
	    
	}
	
	void rdfs(int v,vector<int>trans[],vector<int>&vis)
	{
	    vis[v]=1;
	    
	    for(auto i:trans[v])
	    {
	        if(!vis[i])
	            rdfs(i,trans,vis);
	    }
	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int>s;
        vector<int>vis(n,0);
        int i;
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(adj,i,vis,s);
        }
        
        vector<int>trans[n];
        
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            for(auto j:adj[i])
                trans[j].push_back(i);
        }
        
        int ans=0;
        while(!s.empty())
        {
            int t=s.top();
            s.pop();
            if(!vis[t])
            {
                ans++;
                rdfs(t,trans,vis);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}