//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
# define inf INT_MAX/2
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>>adj[N];
         for(auto e:edges)
         {
             adj[e[0]].push_back({e[2],e[1]});
         }
         vector<int>ans(N,inf);
         ans[0]=0;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
         q.push({0,0});
         while(!q.empty())
         {
             int dis=q.top().first,node=q.top().second;
             q.pop();
             for(auto i:adj[node])
             {
                int cost=i.first,currn=i.second;
                if(cost+dis<ans[currn])
                {
                    ans[currn]=cost+dis;q.push({ans[currn],currn});
                }
             }
         }
         for(int i=0;i<ans.size();i++)
         {
             if(ans[i]==inf)ans[i]=-1;
         }
         return ans;
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends