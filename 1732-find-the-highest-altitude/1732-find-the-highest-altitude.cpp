class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s=0,ma=0;
        for(int i=0;i<gain.size();i++)
        {
            s+=gain[i];
            ma=max(ma,s);
        }
        return ma;
    }
};