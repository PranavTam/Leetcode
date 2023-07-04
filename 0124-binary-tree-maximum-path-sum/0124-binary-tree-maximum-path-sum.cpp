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
    int depth(TreeNode* root,int &maxi)
    {
        if(root==NULL)return 0;
        int lh=max(0,depth(root->left,maxi));
        int rh=max(0,depth(root->right,maxi));
        maxi=max(maxi,lh+rh+root->val);
        return max(lh,rh)+root->val;

    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int t=depth(root,maxi);
        return maxi;
    }
};