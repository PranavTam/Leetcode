
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();








class Solution {
public:
    int titleToNumber(string s) {
        long long  ans=0,m=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans+=(s[i]-'A'+1)*m;
            m*=26;
        }
        return ans;
    }
};