class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int totalFresh=0;
        queue<pair<pair<int,int>,int>>q;
        int vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) totalFresh++;
            }
        }
        int mintime=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            mintime=max(mintime,t);
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0 && grid[newr][newc]==1){
                    q.push({{newr,newc},t+1});
                    vis[newr][newc]=2;
                    cnt++;
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(vis[i][j]==0 && grid[i][j]==1) return -1;
        //     }
        // }
        if(cnt!=totalFresh) return -1;
        return mintime;
    }
};