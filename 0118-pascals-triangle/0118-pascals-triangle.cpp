 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});if(n==1)return ans;
        ans.push_back({1,1});if(n==2)return ans;
        n-=2;
        int it=1;
       
        while(n--)
        {
            vector<int>a;
            a.push_back(1);
            for(int i=0;i<ans[it].size()-1;i++)
            {
                a.push_back(ans[it][i]+ans[it][i+1]);

            }
               a.push_back(1);
               ans.push_back(a);
               it++;
        }
        return ans;
        
    }
};