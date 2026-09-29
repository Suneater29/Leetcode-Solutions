class Solution {
public:
    bool check[105][105][105];
    bool dfs(int m,int n,vector<vector<char>> &grid,int row,int col,int balance){
        if(grid[row][col]=='(') balance++;
        else balance--;
        if(balance<0) return false;
        if(balance>((m-row) + (n-col) -1)) return false;
        if(row==m-1 && col==n-1) return balance==0;
        if(check[row][col][balance]) return false;
        check[row][col][balance]=true;
        if((col+1)<n && dfs(m,n,grid,row,col+1,balance)) return true;
        if((row+1)<m && dfs(m,n,grid,row+1,col,balance)) return true;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if((m+n-1)%2==1) return false;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
        return dfs(m,n,grid,0,0,0);
    }
};