//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& ima, int sr, int sc, int nc) {
        // Code here 
        vector<vector<int>>vi(ima.size(),vector<int>(ima[0].size(),0));
        queue<pair<int,int>>q;
        vector<int>drow={-1,0,+1,0};
        vector<int>dcol={0,+1,0,-1};
        q.push({sr,sc});
        vi[sr][sc]=1;
        int val=ima[sr][sc];
        int n=ima.size(),m=ima[0].size();
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            ima[x][y]=nc;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nx=x+drow[i],ny=y+dcol[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && ima[nx][ny]==val && vi[nx][ny]==0)
                {
                    q.push({nx,ny});
                    vi[nx][ny]=1;
                }
                
                
            }
            // if(x-1>=0 && ima[x-1][y]==val && vi[x-1][y]==0)
            // {
            // q.push({x-1,y});
            // vi[x-1][y]=1;
            // }
            // if(x+1<ima.size() && ima[x+1][y]==val && vi[x+1][y]==0)
            // {
            // q.push({x+1,y});
            // vi[x+1][y]=1;
            // }
            //  if(y-1>=0 && ima[x][y-1]==val && vi[x][y-1]==0)
            // {
            // q.push({x,y-1});
            // vi[x][y-1]=1;
            // }
            // if(y+1<ima[0].size() && ima[x][y+1]==val && vi[x][y+1]==0)
            // {
            // q.push({x,y+1});
            // vi[x][y+1]=1;
            // }
        }
        return ima;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends