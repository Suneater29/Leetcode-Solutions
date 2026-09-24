class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int newr=row+delrow[i];
                int newc=col+delcol[i];
                if(newr>=0 && newr<n && newc>=0 and newc<m){
                    int effort=max(abs(heights[row][col]-heights[newr][newc]),diff);
                    if(effort<dist[newr][newc]){
                        dist[newr][newc]=effort;
                        pq.push({effort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};