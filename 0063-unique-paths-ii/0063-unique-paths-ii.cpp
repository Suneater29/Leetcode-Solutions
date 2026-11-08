class Solution {
public:
    int path(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(row<0 || col<0) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int upPath=path(row-1,col,obstacleGrid,dp);
        int leftPath=path(row,col-1,obstacleGrid,dp);
        return dp[row][col]=upPath+leftPath;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=path(m-1,n-1,obstacleGrid,dp);
        return ans;
    }
};