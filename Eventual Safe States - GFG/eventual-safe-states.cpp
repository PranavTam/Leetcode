//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  bool detectcycle( vector<int> adj[],vector<bool>&vi,vector<bool>&pathvi,int node)
    {
        vi[node]=1;
        pathvi[node]=1;
        for(auto i:adj[node])
        {
            if(!vi[i]){
                if(detectcycle(adj,vi,pathvi,i))return 1;
            }
            else if(pathvi[i])return 1;
        }
        pathvi[node]=0;
        return 0;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool>vi(V,0);
        vector<bool>pathvi(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(!vi[i])
            {
                bool b=detectcycle(adj,vi,pathvi,i);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!pathvi[i])
            {
               ans.push_back(i);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends