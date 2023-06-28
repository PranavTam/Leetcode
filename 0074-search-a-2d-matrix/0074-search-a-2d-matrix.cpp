class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        vector<int>a;
        for(int i=0;i<mat.size();i++)a.push_back(mat[i][0]);
        int idx1=upper_bound(a.begin(),a.end(),tar)-a.begin()-1;
        if(idx1>=0 && idx1<mat.size())
           { int idx2=upper_bound(mat[idx1].begin(),mat[idx1].end(),tar)-mat[idx1].begin()-1;
        if(idx2>=0 && idx2<mat[0].size()&& mat[idx1][idx2]==tar)return 1;}
        return 0;


    }
};