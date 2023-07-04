class Solution {
public:
/*  bool pal(string s)
{  
   vector<char>v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')s[i]=s[i]-'A'+'a';
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='0'&& s[i]<='9')) v.push_back(s[i]);
    }
    int i=0,j=v.size()-1;
     while(i<=j)
     {
         if(v[i]!=v[j])return false;
     }
    return true;


}  */
bool isPalindrome(string s) {
         vector<char>v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')s[i]=s[i]-'A'+'a';
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='0'&& s[i]<='9')) v.push_back(s[i]);
    }
    int i=0,j=v.size()-1;
     while(i<=j)
     {
         if(v[i]!=v[j])return false;
         i++;j--;
     }
    return true;
    }
};