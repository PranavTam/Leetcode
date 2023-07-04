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
long long solve(TreeNode* root,vector<int>&st)
{long long ans=0;
if(root==NULL)
        {long long a=0;long long mul=1;
        int i=st.size()-1;
        for(i;i>=0;i--)
        {a+=st[i]*mul;
          mul*=10;

        }
    
        //cout<<a<<endl;
           return a;
        }
if(root->left!=NULL){st.push_back(root->val);ans+=solve(root->left,st);st.pop_back();}

if(root->right!=NULL){st.push_back(root->val);ans+=solve(root->right,st);st.pop_back();}
if(root->left==NULL && root->right==NULL){st.push_back(root->val);ans+=solve(root->right,st);st.pop_back();}
return ans;
}
public:
    int sumNumbers(TreeNode* root) {
        vector<int>st;int ans=0;
        return solve(root,st);
        
    }
};