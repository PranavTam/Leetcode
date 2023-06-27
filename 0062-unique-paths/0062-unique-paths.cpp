class Solution {
    int solve(int m, int n,map<pair<int,int>,int>&flag)
    {
        if(flag.count(make_pair(m,n)))
        {
            return flag[make_pair(m,n)];
        }
        if(m==1 && n==1)return 1;
        if(m==0 || n==0)return 0;
         int ma=solve(m-1,n,flag)+solve(m,n-1,flag);
         flag[make_pair(m,n)]=ma;
         return flag[make_pair(m,n)];

         
    }
public:
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int>flag;
         return solve(m,n,flag);
     }
};