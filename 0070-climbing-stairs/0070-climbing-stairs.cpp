class Solution {
public:
    int move(int n,vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int oneStep=move(n-1,dp);
        int twoStep=move(n-2,dp);
        return dp[n]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        int one=1;
        int two=1;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++){
            int curr=one+two;
            two=one;
            one=curr;
        }
        return one;
        // vector<int>dp(n+1,-1);
        // return move(n,dp);
    }
};