  const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        int a1,b1,c1;
        while(a.size()!=0 && b.size()!=0)
        {
            a1=a.back()-'0';b1=b.back()-'0';
            c1=a1+b1+carry;
            if(c1==2){ans+='0';carry=1;}
            else if(c1==3){ans+='1';carry=1;}
            else{
                ans+=to_string(c1);carry=0;
            }
            a.pop_back();b.pop_back();
        }
        while(a.size()!=0)
        {
            a1=a.back()-'0';
            c1=a1+carry;
            if(c1==2){ans+='0';carry=1;}
            else if(c1==3){ans+='1';carry=1;}
            else{
                ans+=to_string(c1);carry=0;
            }
            a.pop_back();
        }
        while(b.size()!=0)
        {
            a1=b.back()-'0';
            c1=a1+carry;
            if(c1==2){ans+='0';carry=1;}
            else if(c1==3){ans+='1';carry=1;}
            else{
                ans+=to_string(c1);carry=0;
            }
            b.pop_back();
        }
        if(carry!=0)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
        

    }
};