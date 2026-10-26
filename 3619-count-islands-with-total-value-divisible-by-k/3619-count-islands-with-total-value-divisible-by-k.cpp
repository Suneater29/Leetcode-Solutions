class Solution {
public:
    void dfs(int m,int n,int row,int col,vector<vector<int>> &grid,long long &sum){
        sum+=grid[row][col];
        grid[row][col]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newr=row+delrow[i];
            int newc=col+delcol[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]!=0) dfs(m,n,newr,newc,grid,sum);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum=0;
                    dfs(m,n,i,j,grid,sum);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};