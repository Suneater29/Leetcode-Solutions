class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
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
            }
        }
        int mintime=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
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
                    vis[newr][newc]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1) return -1;
            }
        }
        return mintime;
    }
};