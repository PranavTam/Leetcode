 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
class Solution {
    bool detectcycle(vector<int>adj[],vector<bool>&vi,vector<bool>&pathvi,int node)
    {
        vi[node]=1;
        pathvi[node]=1;
        for(auto i :adj[node])
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
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto e:pre)
        {
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vi(n,0);
        vector<bool>pathvi(n,0);
        for(int i=0;i<n;i++)
        {
            if(detectcycle(adj,vi,pathvi,i))return 0;
        }
        return 1;
    }
};