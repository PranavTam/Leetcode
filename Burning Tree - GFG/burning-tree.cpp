//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int start) 
    {
      map<int,Node*>pa;
         map<int,bool>vi;
         queue<Node*>q;
         q.push(root);
         Node* sta;
         while(!q.empty())
         {
             Node* node=q.front();q.pop();
             vi[node->data]=0;
             if(node->data==start)sta=node;
             if(node->left){pa[node->left->data]=node;q.push(node->left);}
             if(node->right){pa[node->right->data]=node;q.push(node->right);}
         }
         q.push(sta);
         vi[sta->data]=1;
         int ans=-1;
         while(!q.empty())
         {
             int size=q.size();ans++;
             while(size--)
             {
                 Node* node=q.front();q.pop();
                 if(pa.count(node->data) && !vi[pa[node->data]->data]){q.push(pa[node->data]);vi[pa[node->data]->data]=1;}
                 if(node->left && !vi[node->left->data]){q.push(node->left);vi[node->left->data]=1;}
                 if(node->right && !vi[node->right->data]){q.push(node->right);vi[node->right->data]=1;}
             }
         }

         
     return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends