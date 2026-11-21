class Solution {
public:
    int path(int row,int col,vector<vector<int>> &matrix,int n,vector<vector<int>> &dp){
        if(col<0 || col>=n) return INT_MAX;
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int left=path(row+1,col-1,matrix,n,dp);
        int right=path(row+1,col+1,matrix,n,dp);
        int down=path(row+1,col,matrix,n,dp);
        int mini=min(left,min(right,down));
        return dp[row][col]=mini+matrix[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int minpath=path(0,i,matrix,n,dp);
            ans=min(ans,minpath);
        }
        return ans;
    }
};