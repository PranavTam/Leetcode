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
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL)q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();ans++;
            while(size--)
            {
                TreeNode* node=q.front();q.pop();
                if(node->left==NULL && node->right==NULL)return ans;
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);

            }

        }
        return ans;
    }
};