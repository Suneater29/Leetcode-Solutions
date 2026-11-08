class Solution {
public:
    int func(int m,int n,vector<vector<int>> &grid){
        vector<int>rowcnt(m,0);
        vector<int>colcnt(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        int servers=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (rowcnt[i]>1 || colcnt[j]>1)) servers++;
            }
        }
        return servers;
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=func(m,n,grid);
        return ans;
    }
};