class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            ans[row][col]=dist;
            for(int i=0;i<4;i++){
                int nearRow=row+delrow[i];
                int nearCol=col+delcol[i];
                if(nearRow>=0 && nearRow<m && nearCol>=0 && nearCol<n && vis[nearRow][nearCol]==0){
                    vis[nearRow][nearCol]=1;
                    q.push({{nearRow,nearCol},dist+1});
                } 
            }
        }
        return ans;
    }
};