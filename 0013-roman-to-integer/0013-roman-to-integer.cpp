class Solution {
public:
    int letterToInt(char c){
        switch (c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int res=0,cur_val=0,pre_val=0;
        pre_val = letterToInt(s[0]);
        res =pre_val;
        for(int i=1;i<s.size();i++){
            cur_val = letterToInt(s[i]);
            if(cur_val<=pre_val){
                res+=cur_val;
            }
            else{
                res+= cur_val- 2*pre_val;
            }
            pre_val = cur_val;
        }
        return res;
    }
};