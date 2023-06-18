const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:

 
    int maxArea(vector<int>& h) {
       
        int l=0,r=h.size()-1,m=0;
         while(l<r)
         {
             int hi=min(h[l],h[r]);
            m= max(m,(r-l)*hi);
            while(h[l]<=hi && l<r)l++;
            while(h[r]<=hi && l<r)r--;
         }
        return m;

        
    }
};