const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return 0;
       vector<char>a;
       map<char,int>m;
       bool f=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i] )a.push_back(i);
            m[s[i]]++;
            if(m[s[i]]>1)f=1;
        }
        if(a.size()>=3 || a.size()==1)return false;
        if(a.size()==2)
        {
            if(s[a[0]]!=goal[a[1]] || s[a[1]]!=goal[a[0]])return false;
        }
        if(a.size()==0 && f!=1)return false;
        
        return true;
    }
};