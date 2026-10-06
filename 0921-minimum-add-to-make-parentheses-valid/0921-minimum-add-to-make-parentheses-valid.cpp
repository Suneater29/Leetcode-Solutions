class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        for(char c:s){
            if(c=='(') open++;
            else{
                if(open>0) open--;
                else close++;
            }
        }
        int ans=open+close;
        return ans;
    }
};