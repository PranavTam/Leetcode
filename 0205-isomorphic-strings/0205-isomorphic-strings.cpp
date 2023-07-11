class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char>a(256,'#');
          vector<bool>vi(256,0);
        for(int i=0;i<s.size();i++)
        {
            if(a[s[i]-0]=='#' && s[i]!='#')
           { if(vi[t[i]-0]==1)return 0;
              vi[t[i]-0]=1;
               a[s[i]-0]=t[i];}
            else
            {
                  if(a[s[i]-0]!=t[i])return 0;
            }
        }
        return 1;
    }
};