class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.length();
        while(n>k){
            string next="";
            for(int i=0;i<n;i+=k){
                string sub=s.substr(i,k);
                int sum=0;
                for(char c:sub){
                    sum+=c-'0';
                }
                next+=to_string(sum);
            }
            s=next;
            n=s.length();
        }
        return s;
    }
};