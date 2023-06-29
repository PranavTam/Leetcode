class Solution {
    void subset( vector<int>&arr, vector<vector<int>>&ans,vector<int>&sub,int i)
    {
      if(i==arr.size())
      {
          ans.push_back(sub);return;
      }
      sub.push_back(arr[i]);
      subset(arr,ans,sub,i+1);
      sub.pop_back();
      int idx=upper_bound(arr.begin(),arr.end(),arr[i])-arr.begin();
      subset(arr,ans,sub,idx);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     
      sort(nums.begin(),nums.end());
      vector<int>sub;
       vector<vector<int>>ans;
       subset(nums,ans,sub,0);
       return ans;
          


    }
};