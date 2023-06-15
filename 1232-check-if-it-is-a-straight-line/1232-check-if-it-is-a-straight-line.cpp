class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
       int a=co[0][0],b=co[0][1];
       int c=co[1][1]-co[0][1],d=co[1][0]-co[0][0];
       for(int i=2;i<co.size();i++)
       {
           if((co[i][0]-a)*c!=(co[i][1]-b)*d)return 0;
       }
       return 1;
    }
};