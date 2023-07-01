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
    void solve( vector<vector<int>>&ans,TreeNode* root)
    {
        if(root==NULL)return;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           int cnt=q.size();
           vector<int>a;
           for(int i=0;i<cnt;i++)
           {
            TreeNode* node=q.front();
            a.push_back(node->val);
            q.pop();
           if(node->left!=NULL)q.push(node->left);
           if(node->right!=NULL)q.push(node->right);


           }
           ans.push_back(a);
        
       }
      
      
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>>ans;
        //   vector<int>a;
          solve(ans,root);
          return ans;
    }
};