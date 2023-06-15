class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto i:queries)
        {
            int a=0,s=i[0],e=i[1];
            while(s!=e)
            {
                if(s>e)s/=2;
                else e/=2;
                a++;
            }
            ans.push_back(a+1);
        }
        return ans;
    }
};