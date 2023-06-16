//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // int n=mat.size(),m=mat[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        vector<vector<bool>>vi(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1)&& mat[i][j]=='O')
                {
                    ans[i][j]='O';
                    q.push({i,j});vi[i][j]=1;
                }
            }
        }
         vector<int>drows={-1,0,1,0};
	    vector<int>dcols={0,1,0,-1};
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+drows[k],ny=y+dcols[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]=='O' && vi[nx][ny]==0)
                {
                    vi[nx][ny]=1;q.push({nx,ny});ans[nx][ny]='O';
                }
            }
        }
        return ans;
        
        
        
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends