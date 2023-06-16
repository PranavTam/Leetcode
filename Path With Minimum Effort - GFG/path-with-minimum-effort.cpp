//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


# define inf INT_MAX/2
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& hts) {
         int n=hts.size(),m=hts[0].size();
        vector<vector<int>>ans(n,vector<int>(m,inf));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        ans[0][0]=0;
        q.push({0,0,0});
        vector<int>drows={-1,0,1,0};
        vector<int>dcols={0,1,0,-1};
         while(!q.empty())
        {
            int diff=q.top()[0],x=q.top()[1],y=q.top()[2];q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+drows[k],ny=y+dcols[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(max(diff,abs(hts[nx][ny]-hts[x][y]))<ans[nx][ny])
                    {
                        ans[nx][ny]=max(diff,abs(hts[nx][ny]-hts[x][y]));
                        q.push({ans[nx][ny],nx,ny});
                    }
                }
            }
        }
        return ans[n-1][m-1];
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends