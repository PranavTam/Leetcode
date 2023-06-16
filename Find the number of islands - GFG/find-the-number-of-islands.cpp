//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
void dfs(vector<int>adj[],vector<bool>&vi,int node)
    {
        vi[node]=1;
        for(auto i:adj[node])
        {
            if(vi[i]!=1)dfs(adj,vi,i);
        }
    }
    public:
   
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
         
        int n=grid.size(),m=grid[0].size();
        vector<int>adj[n*m];
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int node=i*m+j;
                bool f=0;
              if(grid[i][j]=='1')
              {
                   for(int k=-1;k<2;k++)
                   {
                    for(int l=-1;l<2;l++)
                    {
                        if(i+k>=0 &&j+l>=0 && i+k<n && j+l<m && grid[i+k][j+l]=='1')adj[node].push_back((i+k)*m+j+l),f=1;
                    }
                   }
                   if(f!=1)adj[node].push_back(-2);
                    
                   
              }
              else adj[node].push_back(-1);
            }
        
        }

        int ans=0;
            vector<bool>vi(n*m,0);
            for(int i=0;i<n*m;i++)
            {
                if(adj[i][0]!=-1 && vi[i]==0)
                {if(adj[i][0]==-2)ans++,vi[i]=1;
                else{
                    ans++;
                   
                   dfs(adj,vi,i); }
                   
                }
            }
       
                  
            return ans;
        // Code here
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends