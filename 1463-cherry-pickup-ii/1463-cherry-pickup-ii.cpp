class Solution {
public:
    // int path(int i,int j1,int j2,vector<vector<int>> &grid,int n,int m){
    //     if(j1<0 || j1>=m || j2<0 || j2>=m) return INT_MIN;
    //     if(i==n-1){
    //         if(j1==j2) return grid[i][j1];
    //         else return grid[i][j1]+grid[i][j2];
    //     }
    //     int dj1[]={-1,0,1};
    //     int dj2[]={-1,0,1};
    //     int maxi=INT_MIN;
    //     for(int row=0;row<3;row++){
    //         for(int col=0;col<3;col++){
    //             if(j1==j2){
    //                 maxi=max(maxi,grid[i][j1]+path(i+1,j1+dj1[row],j2+dj2[col],grid,n,m));
    //             }
    //             else{
    //                 maxi=max(maxi,grid[i][j1]+grid[i][j2]+path(i+1,j1+dj1[row],j2+dj2[col],grid,n,m));
    //             }
    //         }
    //     }
    //     return maxi;
    // }
    int path(int i,int j1,int j2,vector<vector<int>> &grid,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return INT_MIN;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int dj1[]={-1,0,1};
        int dj2[]={-1,0,1};
        int res=INT_MIN;
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(j1==j2){
                    res=max(res,grid[i][j1]+path(i+1,j1+dj1[row],j2+dj2[col],grid,n,m,dp));
                }
                else{
                    res=max(res,grid[i][j1]+grid[i][j2]+path(i+1,j1+dj1[row],j2+dj2[col],grid,n,m,dp));
                }
            }
        }
        return dp[i][j1][j2]=res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int ans=path(0,0,m-1,grid,n,m,dp);
        return ans;
    }
};