class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>check(m,-1);
        int p=n-1;
        int q=m-1;
        while(p>=0 && q>=0){
            if(word1[p]==word2[q]){
                check[q]=p;
                q--;
            }
            p--;
        }
        vector<int>ans;
        bool matched=false;
        int j=0;
        for(int i=0;i<n && j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!matched && (j==m-1 || i<check[j+1])){
                ans.push_back(i);
                matched=true;
                j++;
            }
        }
        if(j==m) return ans;
        return {};
    }
};