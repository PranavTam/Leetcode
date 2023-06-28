const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       vector<pair<int,double>>g[n];
      for(int i=0;i<edges.size();i++)
      {
          g[edges[i][0]].push_back({edges[i][1],succProb[i]});
          g[edges[i][1]].push_back({edges[i][0],succProb[i]});
      }
      priority_queue<pair<double,int>>q;
      q.push({1,start});
      vector<double>ans(n,0);
      while(!q.empty())
      {
          int node=q.top().second;
          double p=q.top().first;q.pop();
          for(auto i:g[node])
          {
              double d=i.second*p;
              if(d>ans[i.first])
              {
                  q.push({d,i.first});
                  ans[i.first]=d;
              }
          }

      }
      return ans[end];

    }
};