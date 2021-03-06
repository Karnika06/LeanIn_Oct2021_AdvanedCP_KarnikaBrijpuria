#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        priority_queue<vector<pair<int,int>>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>d(n,INT_MAX);
        
        d[s]=0;
        q.push({0,s});
        
        while(!q.empty())
        {
            auto a=q.top();
            int b=a.first;
            int c=a.second;
            q.pop();
            
           
            for(int i=0;i<adj[c].size();i++)
            {
                int next=adj[c][i][0];
                int dist=adj[c][i][1];;
                if(d[next]>dist+d[c])
                {
                    d[next]=dist+d[c];
                    q.push({d[next],next});
                    
                }
            }
        }
        return d;
        
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}