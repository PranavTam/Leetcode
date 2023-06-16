//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
    void solve(vector<int>&arr,vector<int>&ans,int idx,vector<int>&sub)
    {
        if(idx==arr.size())
        {
           ans.push_back(accumulate(sub.begin(),sub.end(),0));
           return;
        }
        sub.push_back(arr[idx]);
        solve(arr,ans,idx+1,sub);
        sub.pop_back();
        solve(arr,ans,idx+1,sub);
        
        
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans,sub;
        solve(arr,ans,0,sub);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends