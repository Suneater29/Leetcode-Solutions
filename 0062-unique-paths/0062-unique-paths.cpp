class Solution {
public:
    int path(int m,int row,int n,int col,vector<vector<int>> &dp){
        if(row==m-1 && col==n-1) return 1;
        if(row>=m || col>=n) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int downPath=path(m,row+1,n,col,dp);
        int rightPath=path(m,row,n,col+1,dp);
        return dp[row][col]=downPath+rightPath;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=path(m,0,n,0,dp);
        return ans;
    }
};