class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&sub,int i)
    {
       if(i==nums.size()){ans.push_back(sub);return;}
       sub.push_back(nums[i]);
       solve(nums,ans,sub,i+1);
       sub.pop_back();
       solve(nums,ans,sub,i+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>>ans;
          vector<int>sub;
          solve(nums,ans,sub,0);
          return ans;
    }
};