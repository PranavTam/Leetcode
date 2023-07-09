class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,p=pow(2,31);
        while(n!=0)
        {
            ans+=p*(n%2);
            n=n/2;
            p=p/2;

        }
       return ans;
    }
};