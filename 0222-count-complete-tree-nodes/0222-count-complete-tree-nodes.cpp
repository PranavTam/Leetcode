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
    int findheight(TreeNode* root,bool tar)
    {
        if(!root)return 0;
        int ans=0;
        while(root)
        {
            ans++;
            if(tar==0)root=root->left;
            else root=root->right;  
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh=findheight(root,0);
        int rh=findheight(root,1);
        if(lh==rh)return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};