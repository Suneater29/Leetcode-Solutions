class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<int>>dist(n,vector<int>(n,-1));
        dist[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int delrow[]={-1,-1,-1,0,0,1,1,1};
        int delcol[]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int newr=row+delrow[i];
                int newc=col+delcol[i];
                if(newr<0 || newr>=n || newc<0 || newc>=n) continue;
                if(grid[newr][newc]==1 || dist[newr][newc]!=-1) continue;
                dist[newr][newc]=dist[row][col]+1;
                if(newr==n-1 && newc==n-1) return dist[newr][newc];
                q.push({newr,newc});
            }
        }
        return -1;
    }
};