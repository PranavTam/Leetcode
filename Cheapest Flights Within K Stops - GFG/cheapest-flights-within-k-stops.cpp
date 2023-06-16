//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int,int>>adj[n];
        for(auto f:flights)
        {
            adj[f[0]].push_back({f[2],f[1]});
        }
    
        vector<int>ans(n,inf);
        ans[src]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        while(!pq.empty())
        {
        
           
            int node=pq.top()[1],cnt=pq.top()[0],dis=pq.top()[2];pq.pop();
            for(auto i:adj[node])
            {
                int cost=i.first,currn=i.second;
                if(cnt<k+1 && dis+cost<ans[currn])
                {
                    ans[currn]=dis+cost;
                    pq.push({cnt+1,currn,ans[currn]});
                }
            }
    
       
        }
        if(ans[dst]==inf)return -1;
        return ans[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends