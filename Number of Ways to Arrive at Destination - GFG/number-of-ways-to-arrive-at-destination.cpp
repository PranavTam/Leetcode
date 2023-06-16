//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
# define inf 1e15
# define ll long long 
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<ll,ll>>adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        vector<ll>ans(n,inf);
        vector<ll>path(n,0);
        ans[0]=0;
        path[0]=1;
        ll r=0,mod=1e9+7;
        while(!pq.empty())
        {
            ll dis=pq.top().first,node=pq.top().second;pq.pop();
            for(auto j:adj[node])
            {
                ll cost=j.first,currn=j.second;
                if(cost+dis<ans[currn])
                {
                    ans[currn]=cost+dis;
                    pq.push({ans[currn],currn});
                    path[currn]=path[node];
                }
                else if(cost+dis==ans[currn] )
                {
                    path[currn]+=path[node];
                    path[currn]%=mod;
                }
            }

        }
        return path[n-1];
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends