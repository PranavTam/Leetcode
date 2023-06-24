class Solution {
    void solve(vector<int>& arr,int i, int tar,vector<int>pos, vector<vector<int>>&ans)
    {
        if(tar==0)
        {
             ans.push_back(pos);
             return;
        }
        if( i==arr.size() || tar-arr[i]<0 )return;
       
        pos.push_back(arr[i]);
        solve(arr,i,tar-arr[i],pos,ans);
        pos.pop_back();
        solve(arr,i+1,tar,pos,ans);
          
        
      

    }

public:
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        sort(arr.begin(),arr.end());
         vector<vector<int>>ans;
         vector<int>pos;
           solve(arr,0,tar,pos,ans);
           return ans;

    }
};