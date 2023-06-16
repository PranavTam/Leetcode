//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vi(n,vector<bool>(m,0));
        set<vector<pair<int,int>>>ans;
        vector<int>drows={-1,0,1,0};
        vector<int>dcols={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vi[i][j]==0)
                {
                     
                    vector<pair<int,int>>vp;
                    vp.push_back({0,0});
                    queue<pair<int,int>>q;q.push({i,j});vi[i][j]=1;
                    while(!q.empty())
                    {
                        int x=q.front().first,y=q.front().second;q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+drows[k],ny=y+dcols[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && vi[nx][ny]==0)
                            {
                                vp.push_back({nx-i,ny-j});vi[nx][ny]=1;q.push({nx,ny});
                            }
                        }
                    }
                    ans.insert(vp);
                }
            }
        }
        return ans.size();
        // code here
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends