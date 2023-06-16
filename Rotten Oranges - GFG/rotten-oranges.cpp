//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
     int n=grid.size(),m=grid[0].size();
        int cnt=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){q.push({i,j});}
                if(grid[i][j]==0){cnt++;}
            }
        }
        if(cnt==n*m)return 0;
        vector<vector<bool>>vi(n,vector<bool>(m,0));
        vector<int>dro={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
         int ans=-1;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                int x=q.front().first,y=q.front().second;
                grid[x][y]=2;vi[x][y]=1;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx=x+dro[j],ny=y+dcol[j];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && vi[nx][ny]==0 && grid[nx][ny]==1)
                    {
                        vi[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }

            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){return -1;}
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends