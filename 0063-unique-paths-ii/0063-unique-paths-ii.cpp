class Solution {
public:
    int path(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(obstacleGrid[row][col]==1){
                    dp[row][col]=0;
                    continue;
                }
                if(row==0 && col==0){
                    dp[row][col]=1;
                    continue;
                }
                int upPath=0;
                int leftPath=0;
                if(row>0) upPath=dp[row-1][col];
                if(col>0) leftPath=dp[row][col-1];
                dp[row][col]=upPath+leftPath;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans=path(m,n,obstacleGrid,dp);
        return ans;
    }
};