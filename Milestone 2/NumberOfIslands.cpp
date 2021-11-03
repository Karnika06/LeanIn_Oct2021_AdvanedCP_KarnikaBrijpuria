#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
            return;
            
        grid[i][j]='0';
        
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j+1);
        dfs(grid,i+1,j+1);
        dfs(grid,i+1,j-1);
        dfs(grid,i-1,j-1);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int i,j,m=grid.size();
        int n=grid[0].size(),c=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    c++;
                }
            }
        }
     return c;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends