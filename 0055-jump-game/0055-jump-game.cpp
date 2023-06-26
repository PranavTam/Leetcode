class Solution {
    
public:
    bool canJump(vector<int>& nums) 
    {
       int minjumps=0;
       for(int i=nums.size()-2;i>=0;i--)
       {
           minjumps++;
           if(nums[i]>=minjumps)
           {
               minjumps=0;
           }
       }
       if(minjumps==0)return true;
       return false;
        
    }
};