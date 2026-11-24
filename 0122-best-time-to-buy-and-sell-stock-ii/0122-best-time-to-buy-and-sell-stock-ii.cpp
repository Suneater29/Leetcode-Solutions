class Solution {
public:
    //Recursive
    // int maxProf(int ind,int canbuy,vector<int> &prices,int n){
    //     if(ind==n) return 0;
    //     if(canbuy){
    //         int purchase=-prices[ind]+maxProf(ind+1,0,prices,n);
    //         int skip=maxProf(ind+1,1,prices,n);
    //         return max(purchase,skip);
    //     }
    //     else{
    //         int sell=prices[ind]+maxProf(ind+1,1,prices,n);
    //         int hold=maxProf(ind+1,0,prices,n);
    //         return max(sell,hold);
    //     }
    // }


    //Memoization
    // int maxProf(int ind,int canbuy,vector<int> &prices,int n,vector<vector<int>> &dp){
    //     if(ind==n) return 0;
    //     int profit=0;
    //     if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
    //     if(canbuy){
    //         profit=max(-prices[ind]+maxProf(ind+1,0,prices,n,dp),maxProf(ind+1,1,prices,n,dp));
    //     }
    //     else{
    //         profit=max(prices[ind]+maxProf(ind+1,1,prices,n,dp),maxProf(ind+1,0,prices,n,dp));
    //     }
    //     return dp[ind][canbuy]=profit;
    // }

    //Tabulation
    int maxProf(vector<int> &prices,int n,vector<vector<int>> &dp){
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int canbuy=0;canbuy<=1;canbuy++){
                int profit=0;
                if(canbuy){
                    profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
                dp[ind][canbuy]=profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int ans=maxProf(0,1,prices,n);
        // int ans=maxProf(0,1,prices,n,dp);
        int ans=maxProf(prices,n,dp);
        return ans;
    }
};