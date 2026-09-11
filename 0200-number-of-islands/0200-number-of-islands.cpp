class Solution {
public:
    void bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid,int m,int n,int delrow[],int delcol[]){
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
                for(int i=0;i<4;i++){
                    int newr=row+delrow[i];
                    int newc=col+delcol[i];
                    if(newr>=0 && newr<m &&
                       newc>=0 && newc<n &&
                       !vis[newr][newc] &&
                       grid[newr][newc]=='1'){
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                       }
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(!vis[r][c] && grid[r][c]=='1'){
                    cnt++;
                    bfs(r,c,vis,grid,m,n,delrow,delcol);
                }
            }
        }
        return cnt; 
    }
};