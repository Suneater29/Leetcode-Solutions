class Solution {
public:
    int maxProf(int ind,int canbuy,vector<int> &prices,int n,int cap,vector<vector<vector<int>>> &dp){
        if(cap==2) return 0;
        if(ind==n) return 0;
        int profit=0;
        if(dp[ind][canbuy][cap]!=-1) return dp[ind][canbuy][cap];
        if(canbuy){
            profit= max(-prices[ind]+maxProf(ind+1,0,prices,n,cap,dp),maxProf(ind+1,1,prices,n,cap,dp));
        }
        else{
            profit= max(prices[ind]+maxProf(ind+1,1,prices,n,cap+1,dp),maxProf(ind+1,0,prices,n,cap,dp));
        }
        return dp[ind][canbuy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=maxProf(0,1,prices,n,0,dp);
        return ans;
    }
};