class Solution {
public:
    int maxSubArray(vector<int>& nums)
     {
         int ans=INT_MIN,me=0;
         for(int i=0;i<nums.size();i++)
         {
             me=me+nums[i];
              if(ans<me)ans=me;
              if(me<0)me=0;
         }
        return ans;
    }
};