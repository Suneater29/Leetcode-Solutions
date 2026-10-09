class Solution {
public:
    int minInsertions(string s) {
        int insert=0;
        int right=0;
        int ans=0;
        for(char c:s){
            if(c=='('){
                if(right%2==1){
                    insert++;
                    right--;
                }
                right+=2;
            }
            else{
                right--;
                if(right<0){
                    insert++;
                    right+=2;
                }
            }
        }
        ans=insert+right;
        return ans;
    }
};