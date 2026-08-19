class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mpp;
        for(auto it:reservedSeats){
            int row=it[0];
            int col=it[1];
            mpp[row]|=(1<<col);
        }
        int left=(1<<2) | (1<<3) | (1<<4) | (1<<5);
        int mid=(1<<4) | (1<<5) | (1<<6) | (1<<7);
        int right=(1<<6) | (1<<7) | (1<<8) | (1<<9);
        int ans=2*(n-mpp.size());
        for(auto [row,reserved]:mpp){
            bool leftrem=(reserved & left)==0;
            bool midrem=(reserved & mid)==0;
            bool rightrem=(reserved & right)==0;
            if(leftrem && rightrem) ans+=2;
            else if(leftrem || midrem || rightrem) ans+=1;
        }
        return ans;
    }
};