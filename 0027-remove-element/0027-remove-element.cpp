const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1,ans=0;
         for(int k=0;k<nums.size();k++){if(nums[k]==val)ans++;}
        while(i<j)
        {
            while(i<nums.size() && nums[i]!=val)i++;
            while(j>=0 && nums[j]==val)j--;
            if(i<j && nums[i]==val && nums[j]!=val)swap(nums[i],nums[j]);
        }
       
        return nums.size()-ans;
    }
};