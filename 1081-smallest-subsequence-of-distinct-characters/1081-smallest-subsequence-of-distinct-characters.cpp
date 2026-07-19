class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>end(26);
        vector<int>seen(26,0);
        string ans;
        for(int i=0;i<n;i++){
            end[s[i]-'a']=i;
        }   
        for(int i=0;i<n;i++){
            char c=s[i];
            if(seen[c-'a']){
                continue;
            }
            while(!ans.empty() && ans.back()>c && end[ans.back()-'a']>i){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            seen[c-'a']=true;
        }
        return ans;
    }
};