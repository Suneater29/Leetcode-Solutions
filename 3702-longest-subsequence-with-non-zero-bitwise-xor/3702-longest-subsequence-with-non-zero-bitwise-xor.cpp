class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        bool nonZero=false;
        for(int i:nums){
            ans^=i;
            if(i!=0) nonZero=true;
        }
        if(ans!=0) return n;
        else {
            if(nonZero) return n-1;
            else return 0;
        }
    }
};