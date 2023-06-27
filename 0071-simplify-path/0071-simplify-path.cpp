class Solution {
public:
    string simplifyPath(string p) {
       vector<string>v;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='/')continue;
            string t="";
            while(i<p.size() && p[i]!='/')
            {
                t+=p[i];i++;
            }
            if(t==".")continue;
            else if(t==".."){if(v.size()>0)v.pop_back();}
            else v.push_back(t);
        }
        string ans="";
        for(auto i:v)
        {
         ans+='/';ans+=i;
        }
        if(ans.size()==0)return "/";
        return ans;
    }
};