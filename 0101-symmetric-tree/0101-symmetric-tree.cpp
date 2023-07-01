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
void preorder(TreeNode* root,vector<int>&pre)
{
    if(!root)return pre.push_back(101);
    pre.push_back(root->val);
    preorder(root->left,pre);
    preorder(root->right,pre);
}
void postorder(TreeNode* root,vector<int>&post)
{
    if(!root)return post.push_back(101);
       postorder(root->left,post);
       postorder(root->right,post);
          post.push_back(root->val);
}

    bool isSymmetric(TreeNode* root) {
        TreeNode*t=root;
       vector<int>pre;
       preorder(root,pre);
       vector<int>post;
       postorder(t,post);
       for(int i=0;i<pre.size();i++)
       {
           if(pre[i]!=post[post.size()-1-i])return false;
       }
       return true;

    }
};