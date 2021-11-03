#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    bool valid(int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m  )
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        queue<pair<int,int>>q;
        
        int i,j,row=grid.size(),col=grid[0].size(),ans=0,c=0;
        
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                {
                     c++;
                }
                  
            }
        }
        
        while(!q.empty())
        {
            int m=q.size();
    
            for(i=0;i<m;i++)
            {
                int a=q.front().first;
                int b=q.front().second;
               
                q.pop();
                
                int dx[]={1,-1,0,0};
                int dy[]={0,0,-1,1};
                
                for(j = 0 ; j<4 ; j++)
                {
                    if(valid(a+dx[j], b+dy[j], row, col))
                    {
                         
                        if( grid[a+dx[j]][b+dy[j]]==1 )
                        {
                            c--;
                            grid[a+dx[j]][b+dy[j]]=2;
                            q.push({a+dx[j],b+dy[j]});
                        }
                        
                    }
                  
                }
                
            }
             if(!q.empty())
                ans++;
        }
        
        if(c==0)
            return ans;
        return -1;
    }
};

// { Driver Code Starts.
int main(){
    int tc;
	cin >> tc;
	while(tc--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends