
 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>a;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
             string s=strs[i];
             sort(s.begin(),s.end());
             a[s].push_back(strs[i]);
        }
        for(auto i:a)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};