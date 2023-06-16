//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
         int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vi(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1)&& grid[i][j]==1)
                {
                        q.push({i,j});vi[i][j]=1; grid[i][j]=0;
                }
            }
        }
        vector<int>drows={-1,0,1,0};
        vector<int>dcols={0,1,0,-1};
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+drows[i],ny=y+dcols[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && vi[nx][ny]==0)
                {
                     grid[nx][ny]=0;q.push({nx,ny});vi[nx][ny]=1;
                }

            }
        }
        int ans=0;
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( grid[i][j]==1)
                {
                     ans++;  
                }
            }
        }
        return ans;
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends