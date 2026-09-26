class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        string ans="";
        unordered_map<string,string>mpp;
        for(auto &it:knowledge){
            mpp[it[0]]=it[1];
        }
        int ind=0;
        while(ind<n){
            if(s[ind]=='('){
                ind++;
                string key="";
                while(ind<n && s[ind]!=')'){
                    key+=s[ind];
                    ind++;
                }
                ind++;
                if(mpp.count(key)) ans+=mpp[key];
                else ans+='?';
            }
            else{
                ans+=s[ind];
                ind++;
            }
        }
        return ans;
    }
};