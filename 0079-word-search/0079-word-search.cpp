class Solution {
    bool dfs(vector<vector<char>>&b,string &w,int x,int y)
    {
        int n=b.size(),m=b[0].size();
        if(w.size()==0)return 1;
        if(x<0 || x>=n || y<0 || y>=m || b[x][y]!=w[0])return 0;
        char ch=b[x][y];
        b[x][y]='#';
        string s=w.substr(1);
       bool ans=dfs(b,s,x-1,y)||dfs(b,s,x,y+1)||dfs(b,s,x+1,y)||dfs(b,s,x,y-1);
       b[x][y]=ch;
       return ans;
       
       

    }
public:
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size(),m=b[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
            if (dfs(b,w,i,j))return 1;
                   
                 
                
            }
        }
        return 0;
    }
};