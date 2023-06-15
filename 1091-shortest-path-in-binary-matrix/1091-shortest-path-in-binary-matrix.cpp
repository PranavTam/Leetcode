const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
# define inf INT_MAX/2
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0])return -1;
       int n=grid.size(),m=grid[0].size();
        pair<int, int> sc={0,0};
        pair<int,int>des={n-1,n-1};
       if(grid[n-1][n-1])return -1;
       vector<vector<int>>ans(n,vector<int>(m,inf)); 
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
       q.push({0,sc.first,sc.second});
       ans[sc.first][sc.second]=0;
       vector<int>drows={-1,-1,-1,0,1,1,1,0};
       vector<int>dcols={-1,0,1,1,1,0,-1,-1};
       while(!q.empty())
       {
           int dis=q.top()[0],x=q.top()[1],y=q.top()[2];q.pop();
           for(int k=0;k<8;k++)
           {
               int nx=x+drows[k],ny=y+dcols[k];
               if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0)
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
       return ans[tx][ty]+1;
        
                         
    }
};