//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
    bool dfs(vector<int>adj[],vector<bool>&vi,vector<bool>&pathvi,vector<int>&ans,int node)
    {
        vi[node]=1;
        pathvi[node]=1;
        for(auto i:adj[node])
        {
            if(!vi[i]){
                if(dfs(adj,vi,pathvi,ans,i))return 1;
            }
            else if(pathvi[i])return 1;
        }
        pathvi[node]=0;
        ans.push_back(node);
        return 0;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=1;i<N;i++)
        {int s1=0;
        int m=min(dict[i].size(),dict[i-1].size());
            while(s1<m && dict[i][s1]==dict[i-1][s1])
            {
                s1++;
            }
           if(s1<m) adj[dict[i-1][s1]-'a'].push_back(dict[i][s1]-'a');
        }
        
        vector<bool>vi(K,0);vector<bool>pathvi(K,0);
        vector<int>ans;
        for(int i=0;i<K;i++)
        {
            if(!vi[i])
            {
                bool d=dfs(adj,vi,pathvi,ans,i);
            }
        }
        reverse(ans.begin(),ans.end());
        string s="";
        for(auto i:ans)
        {
           s+=('a'+i); 
        }
        // cout<<s<<endl;
        return s;
        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends