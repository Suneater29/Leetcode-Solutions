class Solution {
public:
    void generate(int n,vector<vector<string>> &ans,vector<string> &board,vector<int> &leftrow,vector<int> &updiag,vector<int> &downdiag,int index){
        if(index==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(leftrow[i]==0 && downdiag[i+index]==0 && updiag[(n-1)+(index-i)]==0){
                board[index][i]='Q';
                leftrow[i]=1;
                updiag[(n-1)+(index-i)]=1;
                downdiag[i+index]=1;
                generate(n,ans,board,leftrow,updiag,downdiag,index+1);
                board[index][i]='.';
                leftrow[i]=0;
                updiag[(n-1)+(index-i)]=0;
                downdiag[i+index]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>leftrow(n,0);
        vector<int>updiag(2*n-1,0);
        vector<int>downdiag(2*n-1,0);
        generate(n,ans,board,leftrow,updiag,downdiag,0);
        return ans;
    }
};