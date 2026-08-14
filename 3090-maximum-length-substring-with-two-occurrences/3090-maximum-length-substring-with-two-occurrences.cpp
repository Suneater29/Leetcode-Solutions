class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int>mpp(26,0);
        int ans=0;
        int low=0;
        for(int high=0;high<n;high++){
            mpp[s[high]-'a']++;
            while(mpp[s[high]-'a']>2){
                mpp[s[low]-'a']--;
                low++;
            }
            ans=max(ans,high-low+1);
        }
        return ans;
    }
};