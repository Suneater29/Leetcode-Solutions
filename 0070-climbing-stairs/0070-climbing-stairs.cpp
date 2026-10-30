class Solution {
public:
    int move(int n,vector<int> &dp){
        if(n<=1) return 1;
        // if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int oneStep=move(n-1,dp);
        int twoStep=move(n-2,dp);
        return dp[n]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return move(n,dp);
    }
};