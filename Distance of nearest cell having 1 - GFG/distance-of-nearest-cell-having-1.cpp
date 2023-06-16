//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{int n=grid.size(),m=grid[0].size();
	    vector<vector<bool>>vi(n,vector<bool>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1){q.push({i,j});vi[i][j]=1;}
	        }
	    }
	    vector<int>drows={-1,0,1,0};
	    vector<int>dcols={0,1,0,-1};
	    int dis=0;
	    while(!q.empty())
	    {
	        dis++;
	        int size=q.size();
	        for(int i=0;i<size;i++)
	        {
	            int x=q.front().first,y=q.front().second;
	            q.pop();
	            for(int k=0;k<4;k++)
	            {
	                int nx=x+drows[k],ny=y+dcols[k];
	                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 && vi[nx][ny]==0)
	                {
	                    q.push({nx,ny});vi[nx][ny]=1;ans[nx][ny]=dis;
	                }
	            }
	            
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends