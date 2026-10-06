class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int t=top[0];
            int r=top[1];
            int c=top[2];
            if(r==n-1 && c==n-1) return t;
            if(t>dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<n){
                    int nextCell=max(t,grid[newr][newc]);
                    if(nextCell<dist[newr][newc]){
                        dist[newr][newc]=nextCell;
                        pq.push({nextCell,newr,newc});
                    }
                }
            }
        }
        return 0;
    }
};