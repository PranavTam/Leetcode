class Solution {

public:
   void solve(vector<vector<int>>& matrix,vector<int>&ans,int l,int r,int t,int b)
    {
        if(l>r || t>b)return;
        for(int i=l;i<=r;i++)
        {
            ans.push_back(matrix[l][i]);
            
        }
         t++;
        for(int i=t;i<=b;i++)
        {
            ans.push_back(matrix[i][r]);
          
        }
        r--;
        if(l>r || t>b)return;
        for(int i=r;i>=l;i--)
        {
            ans.push_back(matrix[b][i]);
          
        }
           b--;
        for(int i=b;i>=t;i--)
        {
            ans.push_back(matrix[i][l]);
           
        }
        l++;
        solve(matrix,ans,l,r,t,b);


     }
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int>ans;
        solve(matrix,ans,0,matrix[0].size()-1,0,matrix.size()-1);
        return ans;
    }
};