class Solution {
public:
    int maxProf(int ind,int canbuy,vector<int> &prices,int n,vector<vector<int>> &dp){
        if(ind>=n) return 0;
        int profit=0;
        if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
        if(canbuy){
            profit=max(-prices[ind]+maxProf(ind+1,0,prices,n,dp),maxProf(ind+1,1,prices,n,dp));
        }
        else{
            profit=max(prices[ind]+maxProf(ind+2,1,prices,n,dp),maxProf(ind+1,0,prices,n,dp));
        }
        return dp[ind][canbuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans=maxProf(0,1,prices,n,dp);
        return ans;
    }
};