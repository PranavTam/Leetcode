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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         queue<TreeNode*>q;
         q.push(root);
         int f=1;
         while(!q.empty())
         {
             int size=q.size();
             vector<int>a;f++;
             for(int i=0;i<size;i++)
             {
                 TreeNode* node=q.front();q.pop();
                 if(node!=NULL)
                 {
                     q.push(node->left);
                     q.push(node->right);
                     a.push_back(node->val);

                 }
             }
             if(f%2)reverse(a.begin(),a.end());
             ans.push_back(a);
         }
         ans.pop_back();
         return ans;
    }
};