/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool>vi;
        parent[root]=NULL;
        vi[root]=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();q.pop();
                if(node->left){parent[node->left]=node;vi[node->left]=0;q.push(node->left);}
                if(node->right){parent[node->right]=node;vi[node->right]=0;q.push(node->right);}
            }
        }

        q.push(target);
        vi[target]=1;
        int le=-1;
        while(!q.empty())
        {
            int size=q.size();le++;
            while(size--)
            {
                TreeNode* node=q.front();q.pop();
                if(le==k){ans.push_back(node->val);}
                else
                {
                if(node->left && vi[node->left]==0){vi[node->left]=1;q.push(node->left);}
                if(node->right &&   vi[node->right]==0){vi[node->right]=1;q.push(node->right);}
                if(parent[node] && vi[parent[node]]==0){vi[parent[node]]=1;q.push(parent[node]);}
                }
              
                
            }
            if(le==k)return ans;
        }
    return ans;
    }
};