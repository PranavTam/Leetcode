class Solution {
public:
     int find(vector<int>& nums,int s,int e)
     {
         int mid=(s+e)/2;
         while(s<e)
         {
             if(nums[mid]>nums[e]){ s=mid+1;}
             else if(nums[mid]<nums[e]) e=mid;
             else e--;
             mid=(s+e)/2;
         }
        return nums[mid];
     }

    int findMin(vector<int>& nums) {

        return find(nums,0,nums.size()-1);
    }
};