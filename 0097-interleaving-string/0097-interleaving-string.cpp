class Solution {
    bool solve(string &s1, string &s2, string &s3,int i,int j,int k)
    {
       if(i<0 &&j<0 && k<0)return 1;
       if(i>=0 && s3[k]==s1[i] && j>=0 && s3[k]==s2[j]){
           return (solve(s1,s2,s3,i-1,j,k-1) || solve(s1,s2,s3,i,j-1,k-1));
       }
       else if(i>=0 && s3[k]==s1[i])return solve(s1,s2,s3,i-1,j,k-1);
       else if(j>=0 && s3[k]==s2[j]) return solve(s1,s2,s3,i,j-1,k-1);
       return 0;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
       if(s1.size()+s2.size()!=s3.size())return 0;
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
    }
};