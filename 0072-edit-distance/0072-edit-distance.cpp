 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 





class Solution {
public:
    int minDistance(string str1, string str2) {
    vector<vector<int>>dp(str2.size()+1,vector<int>(str1.size()+1,0));
    for(int i=1;i<dp.size();i++)dp[i][0]=1+dp[i-1][0];
    for(int i=1;i<dp[0].size();i++)dp[0][i]=1+dp[0][i-1];
    for(int i=1;i<=str2.size();i++)
    {
        for(int j=1;j<=str1.size();j++)
        {
            if(str2[i-1]==str1[j-1])dp[i][j]=dp[i-1][j-1];
            else if(i==j)dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            else if(i>j)dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            else dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
        }
    }
return dp[str2.size()][str1.size()];


    }
};