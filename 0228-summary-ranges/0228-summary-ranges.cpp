class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)return {};
       vector<string>ans; 
        int a=nums[0],b;
        for(int i=0;i<nums.size();i++)
        {
            b=nums[i];
            if(i!=0){
                if(b-1!=nums[i-1] )
                {
                    if(a==nums[i-1])ans.push_back(to_string(a));
                    else ans.push_back(to_string(a)+"->"+to_string(nums[i-1]));
                    a=b;
                }
            }
            if(i==nums.size()-1)
                {
                    if(a==nums[i])ans.push_back(to_string(a));
                    else ans.push_back(to_string(a)+"->"+to_string(nums[i]));
                    a=b;
                }
           
        }

        return ans;
    }
};