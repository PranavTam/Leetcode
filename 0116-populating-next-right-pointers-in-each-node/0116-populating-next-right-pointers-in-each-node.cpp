/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
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
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            Node* back;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if(i==0)back=node;
                else if(i==size-1){back->next=node;node->next==NULL;}
                else
                {
                    back->next=node;
                    back=node;
                }


            }
        }
        return root;
    }
};