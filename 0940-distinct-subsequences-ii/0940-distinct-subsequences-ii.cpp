class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD=1e9+7;
        long long total=0;
        vector<long long>last(26,0);
        for(char c:s){
            int index=c-'a';
            long long added=(total+1-last[index]+MOD)%MOD;
            total=(total+added)%MOD;
            last[index]=(last[index]+added)%MOD;
        }
        return total;
    }
};