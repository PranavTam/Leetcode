vector<int> v(47,0);

class Solution {
public:
     
    int climbStairs(int n) {
         if(n==0) return 1;
        if(n==1)return 1;
        if(v[n]!=0)return v[n];
         v[n]= climbStairs(n-1)+climbStairs(n-2);
         return v[n];
        
    }
};