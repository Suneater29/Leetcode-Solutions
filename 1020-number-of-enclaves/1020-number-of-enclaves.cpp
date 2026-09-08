class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,int delrow[],int delcol[],int m,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+delrow[i];
            int newc=c+delcol[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && !vis[newr][newc] && grid[newr][newc]==1){
                dfs(newr,newc,vis,grid,delrow,delcol,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid,delrow,delcol,m,n);
            }
            if(!vis[m-1][j] && grid[m-1][j]==1){
                dfs(m-1,j,vis,grid,delrow,delcol,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,delrow,delcol,m,n);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,vis,grid,delrow,delcol,m,n);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};