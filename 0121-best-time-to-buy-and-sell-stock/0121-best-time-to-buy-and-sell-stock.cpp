const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[prices.size()-1],p=0;
        for(int i=prices.size()-2;i>=0 ;i--)
        {
            m=max(m,prices[i]);

           /*  if(prices[i]>m)
            {
                m=prices[i];
            } 
            else */
         p=max(p,(m-prices[i]));

        }
        return p;
    }
};