class Solution {
public:
    // void dfs(int row,int col,vector<vector<int>> &grid,int m,int n,long long val,long long &ans){
    //     val^=grid[row][col];
    //     if(row==m-1 && col==n-1){
    //         ans=min(ans,val);
    //         return;
    //     }
    //     if(row+1<m) dfs(row+1,col,grid,m,n,val,ans);
    //     if(col+1<n) dfs(row,col+1,grid,m,n,val,ans);
    // }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bitset<1024>>>dp(m,vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i > 0){
                    for(int k=0;k<1024;k++){
                        if(dp[i-1][j][k]){
                            dp[i][j][k^grid[i][j]]=1;
                        }
                    }
                }
                if(j>0){
                    for(int m=0;m<1024;m++){
                        if(dp[i][j-1][m]){
                            dp[i][j][m^grid[i][j]]=1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<1024;i++) {
            if (dp[m-1][n-1][i]) return i;
        }
        return -1;
    }
};