class Solution {
public:
    // int maxProf(vector<int> &prices,int n,int fee,vector<vector<int>> &dp){
    //     for (int ind = n - 1; ind >= 0; ind--) {
    //         for (int canbuy = 0; canbuy <= 1; canbuy++) {
    //             int profit = 0;
    //             if (canbuy) {
    //                 profit = max(-prices[ind]+dp[ind + 1][0], dp[ind + 1][1]);
    //             }
    //             else {
    //                 profit = max(prices[ind]-fee+dp[ind + 1][1], dp[ind + 1][0]);
    //             }
    //             dp[ind][canbuy] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int frontNotBuy,frontBuy,currNotBuy,currBuy;
        frontNotBuy=frontBuy=0;
        for(int ind=n-1;ind>=0;ind--){
            int profit=0;
            currBuy=max(-prices[ind]+frontNotBuy,frontBuy);
            currNotBuy=max(prices[ind]-fee+frontBuy,frontNotBuy);
            frontNotBuy=currNotBuy;
            frontBuy=currBuy;
        }
        return frontBuy;
    }
};