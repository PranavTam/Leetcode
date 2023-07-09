const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n !=0)
        {
          c+=(n%2);
         n=n/2;
        }
        return c;
    }
};