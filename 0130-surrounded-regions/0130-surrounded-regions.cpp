class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &board,int delrow[],int delcol[],int m,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+delrow[i];
            int newc=c+delcol[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && !vis[newr][newc] && board[newr][newc]=='O'){
                dfs(newr,newc,vis,board,delrow,delcol,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,delrow,delcol,m,n);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,vis,board,delrow,delcol,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delrow,delcol,m,n);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board,delrow,delcol,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};