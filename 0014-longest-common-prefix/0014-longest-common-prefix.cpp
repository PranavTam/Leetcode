 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
/* int init = [] {
    ios_base::sync_with_stdio(false); // turn off sync
    cin.tie(nullptr);  // untie in/out streams
    ofstream out("user.out"); // redirect stdout to user.out
     for (string s; getline(cin, s);)  // read a line into s
        out << (equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin()+1) ? "true\n" : "false\n");  // write to user.out
    out.flush(); // flush the buffer
    exit(0);  // exit normally
    return 0;
}(); */



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
         sort(strs.begin(),strs.end());
         string a=strs[0];
         string b=strs[strs.size()-1];
         string ans="";
         for(int i=0;i<a.size();i++)
         {
             if(a[i]==b[i])ans+=a[i];
             else break;
         }
        return ans;
    }
};