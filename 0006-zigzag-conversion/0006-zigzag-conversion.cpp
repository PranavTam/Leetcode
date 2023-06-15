 
class Solution {
public:
    string convert(string s, int numRows) {
        string re="";
        vector<string>ans(numRows,"");
        int n=s.size();
        int i=0;
        while(i<n)
        {
            for(int j=0;i<n && j<numRows;j++,i++)ans[j]+=s[i];
            for(int j=numRows-2;i<n && j>0;j--,i++)ans[j]+=s[i];
        }
        for(auto i: ans){re+=i;}
        return re;

    }
};