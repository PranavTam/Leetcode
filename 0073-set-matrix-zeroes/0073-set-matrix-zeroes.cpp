class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         map<int,int>rows;
         map<int,int>columns;
         int ro=matrix.size();
         int col=matrix[0].size();
         for(int i=0;i<ro;i++)
         {
             for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                rows[i]++;
                columns[j]++;
                }
            }
         }
         for(auto i:rows)
         {
             for(int j=0;j<col;j++)
            {
                matrix[i.first][j]=0;
            }
         }
        for(auto i: columns)
         {
             for(int j=0;j<ro;j++)
            {
                matrix[j][i.first]=0;
            }
         }


    }
};