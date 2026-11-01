class Solution {
public:
    int rob(vector<int> &nums,int n,vector<int> &dp){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+rob(nums,n-2,dp);
        int leave=rob(nums,n-1,dp);
        return dp[n]=max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=rob(nums,n-1,dp);
        return ans;
    }
};