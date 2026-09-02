class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &temp,vector<vector<int>> &image,int color,int delrow[],int delcol[],int initial){
        int m=image.size();
        int n=image[0].size();
        temp[sr][sc]=color;
        for(int i=0;i<4;i++){
            int newr=sr+delrow[i];
            int newc=sc+delcol[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && image[newr][newc]==initial && temp[newr][newc]!=color){
                dfs(newr,newc,temp,image,color,delrow,delcol,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>temp=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,temp,image,color,delrow,delcol,initial);
        return temp;
    }
};