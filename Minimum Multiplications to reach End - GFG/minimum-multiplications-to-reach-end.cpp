//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
# define inf INT_MAX/2
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n=arr.size();
        queue<pair<int,int>>q;
        q.push({start,0});
        int mod=1e5;
        vector<int>ans(mod,inf);
        ans[start]=0;
        while(!q.empty())
        {
            int node=q.front().first,steps=q.front().second;q.pop();
            for(auto j:arr)
            {
                int nw=j*node;
                nw%=mod;
                if(steps+1<ans[nw])
                {
                    ans[nw]=steps+1;
                    if(nw==end)return steps+1;
                    q.push({nw,steps+1});
                }
            }
            
        }
        return -1;
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends