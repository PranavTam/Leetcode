 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void rotate(vector<int>& v, int k) {
       k=k%v.size();
       reverse(v.begin(),v.end());
       reverse(v.begin(),v.begin()+k);
       reverse(v.begin()+k,v.end());
    }
};