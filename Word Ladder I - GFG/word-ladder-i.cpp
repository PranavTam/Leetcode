//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

# define inf INT_MAX/2
class Solution {
    bool help(string &s1,string &s2)
    {
        int cnt=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])cnt++;
        }
        if(cnt==1)return 1;
        return 0;
    }
public:
    int wordLadderLength(string sw, string tw, vector<string>& wl) {
        bool f=0,f1=0;
        for(auto i:wl){
            if(i==sw)f=1;
            if(i==tw)f1=1;
        }
        if(!f1)return 0;
        if(!f)wl.push_back(sw);
        map<string,int>idx;
        for(int i=0;i<wl.size();i++){idx[wl[i]]=i;}
        map<string,vector<pair<int,string>>>ma;
        for(int i=0;i<wl.size();i++)
        {
            for(int j=0;j<wl.size();j++)
            {
                if(help(wl[i],wl[j]))ma[wl[i]].push_back({1,wl[j]});
            }
        }
        vector<int>ans(wl.size(),inf);
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>q;
        q.push({0,sw});
        ans[idx[sw]]=0;
        while(!q.empty())
        {
            int dis=q.top().first;
            string node=q.top().second;q.pop();
            for(auto i:ma[node])
            {
                int cost=i.first;
                string currn=i.second;
                if(cost+dis<ans[idx[currn]])
                {
                    ans[idx[currn]]=cost+dis;q.push({ans[idx[currn]],currn});
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==inf)ans[i]=0;
        }
        if(ans[idx[tw]]==0)return 0;
        return ans[idx[tw]]+1;
        
        
        
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends