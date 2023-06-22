class Solution {
public:
   void gpar(int n,int o,int c,vector<string>&ans,string out)
    {
         if(o==n && c==n)
         {
             ans.push_back(out);
         }
         if(o<n)
         {
             gpar(n,o+1,c,ans,out+"(");
         }
         if(c<o)
         {
            gpar(n,o,c+1,ans,out+")");  
         }


    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        string out="";
       // n--;
        gpar(n,0,0,ans,out);
       
      
        return ans;

    }
};