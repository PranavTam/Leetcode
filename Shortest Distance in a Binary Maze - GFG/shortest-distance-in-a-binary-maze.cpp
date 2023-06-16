//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
# define inf INT_MAX/2
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> sc,
                     pair<int, int> des) {
        // if(grid[sc.first][sc.second]==0)return -1;
         int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,inf)); 
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
       q.push({0,sc.first,sc.second});
       ans[sc.first][sc.second]=0;
       vector<int>drows={-1,0,1,0};
       vector<int>dcols={0,1,0,-1};
       while(!q.empty())
       {
           int dis=q.top()[0],x=q.top()[1],y=q.top()[2];q.pop();
           for(int k=0;k<4;k++)
           {
               int nx=x+drows[k],ny=y+dcols[k];
               if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
               {
                   if(dis+1<ans[nx][ny])
                   {
                       ans[nx][ny]=dis+1;q.push({dis+1,nx,ny});
                   }
               }
           }
       }
       int tx=des.first,ty=des.second;
       if(ans[tx][ty]==inf)return -1;
       return ans[tx][ty];
        
                         
                         
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends