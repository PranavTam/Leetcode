 

class Solution {
    unordered_map<string,bool>memo;
    bool solve(string target, vector<string>& wordDict)
    {
        if(memo.count(target))
        {
           return memo[target]; 
        }
        if(target=="")return 1;
        for(auto word: wordDict)
        {
            if(target.find(word)==0)
            {
                string val=target.substr(word.size());
                if(solve(val,wordDict))
                {memo[target]=1;
                    return 1;
                }
            }
        }
       memo[target]=0;
       return 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s,wordDict);
    }
};