const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
    int solve(vector<int>&nums,int i, vector<int>&dp)
    {
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];

        int pick,notpick;
        pick=nums[i]+solve(nums,i-2,dp);
        notpick=solve(nums,i-1,dp);

        dp[i]=max(pick,notpick);
        return max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        vector<int>dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);
        return max(solve(temp1,nums.size()-2,dp1),solve(temp2,nums.size()-2,dp2));
    }
};