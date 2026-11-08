class Solution {
public: 
    // int pathSum(int row,int col,vector<vector<int>> &matrix,int n){
    //     if(col<0 || col>=n) return INT_MAX;
    //     if(row==n-1) return matrix[row][col];
    //     int left=pathSum(row+1,col-1,matrix,n);
    //     int right=pathSum(row+1,col+1,matrix,n);
    //     int down=pathSum(row+1,col,matrix,n);
    //     int mini=min(left,min(right,down));
    //     return matrix[row][col]+mini;
    // }

    int pathSum(int row,int col,vector<vector<int>> &matrix,int n,vector<vector<int>> &dp){
        if(col<0 || col>=n) return INT_MAX;
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int left=pathSum(row+1,col-1,matrix,n,dp);
        int right=pathSum(row+1,col+1,matrix,n,dp);
        int down=pathSum(row+1,col,matrix,n,dp);
        int mini=min(left,min(right,down));
        return dp[row][col]=matrix[row][col]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            int minsum=pathSum(0,i,matrix,n,dp);
            ans=min(ans,minsum);
        }
        return ans;
    }
};