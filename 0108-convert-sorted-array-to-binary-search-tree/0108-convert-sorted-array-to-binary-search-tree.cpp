/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
  const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
class Solution {
public:
TreeNode* ans(vector<int>& nums,int s ,int e)
{
     if(e<s)return NULL;
        TreeNode* root=new TreeNode();
        int mid=(s+e)/2;
        root->val=nums[mid];
        root->left=ans( nums,s,mid-1);
        root->right=ans( nums,mid+1,e);
        return root;   
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ans(nums,0,nums.size()-1);
        
}
};