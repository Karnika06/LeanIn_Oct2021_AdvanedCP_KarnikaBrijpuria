// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(vector<bool>&vis,vector<int>&dist,vector<int>&low,stack<int>&s,vector<int>adj[],int u,vector<vector<int>>&ans)
    {
        static int time=0;
      
        dist[u]=low[u]=++time;
        vis[u]=true;
        s.push(u);
        
        for(auto v:adj[u])
        {
            if(dist[v]==-1)
            {
                dfs(vis,dist,low,s,adj,v,ans);
                low[u]=min(low[u],low[v]);
            }
            else if(vis[v])
            {
                low[u]=min(low[u],dist[v]);
            }
        }
        if(low[u]==dist[u])
        {
            vector<int>v;
            while(s.top()!=u)
            {
                v.push_back(s.top());
                vis[s.top()]=false;
                s.pop();
            }
            v.push_back(s.top());
            vis[s.top()]=false;
            s.pop();
            ans.push_back(v);
            v.clear();
        }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        vector<vector<int>>ans;
        int i;
        vector<bool>vis(n,false);
        vector<int>dist(n,-1);
        vector<int>low(n,-1);
        stack<int>s;
        
        for(i=0;i<n;i++)
        {
            if(dist[i]==-1)
                dfs(vis,dist,low,s,adj,i,ans);
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}
