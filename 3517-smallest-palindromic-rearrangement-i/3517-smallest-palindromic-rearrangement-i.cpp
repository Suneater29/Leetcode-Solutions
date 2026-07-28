class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        // unordered_map<char,int>mpp;
        vector<int>mpp(26,0);
        for(char c:s){
            mpp[c-'a']++;
        }
        string leftpart="";
        char middle='\0';
        for(int i=0;i<26;i++){
            leftpart.append(mpp[i]/2,char('a'+i));
            if(mpp[i]%2==1){
                middle=char('a'+i);
            }
        }
        string rightpart=leftpart;
        reverse(rightpart.begin(),rightpart.end());
        if(middle=='\0'){
            return leftpart+rightpart;
        }
        return leftpart+string(1,middle)+rightpart;
    }
};