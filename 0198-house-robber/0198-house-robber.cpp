class Solution {
    int solve(vector<int>& nums,int i,vector<int>&dp)
    {
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];

        int pick=INT_MIN,notpick=INT_MIN;
        pick=nums[i]+solve(nums,i-2,dp);
        notpick=solve(nums,i-1,dp);

        dp[i]=max(pick,notpick);
        return max(pick,notpick);

    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};