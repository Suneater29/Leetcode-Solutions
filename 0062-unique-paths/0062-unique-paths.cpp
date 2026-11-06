class Solution {
public:
    // int path(int m,int row,int n,int col,vector<vector<int>> &dp){
    //     if(row==m-1 && col==n-1) return 1;
    //     if(row>=m || col>=n) return 0;
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int downPath=path(m,row+1,n,col,dp);
    //     int rightPath=path(m,row,n,col+1,dp);
    //     return dp[row][col]=downPath+rightPath;
    // }
    int path(int m,int n,vector<vector<int>> &dp){
        dp[m-1][n-1]=1;
        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(row==m-1 && col==n-1) continue;
                int downPath=0;
                int rightPath=0;
                if(row+1<m) downPath=dp[row+1][col];
                if(col+1<n) rightPath=dp[row][col+1];
                dp[row][col]=downPath+rightPath;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=path(m,n,dp);
        return ans;
    }
};