const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int i=0,j=0,sum=0,ans=INT_MAX;
       while(i<nums.size() && j<nums.size()+1)
       {
           if(sum>=target)
           {
              ans=min(ans,j-i);
              while(true)
              {
                if(sum<target)break;
                sum-=nums[i];
                i++;
               if(sum>=target)ans=min(ans,j-i);
              }
           }
           else 
           {
             if(j<nums.size())  sum+=nums[j];
               j++;
           }
       } 
       if(ans==INT_MAX)return 0;
       return ans;
    }
};