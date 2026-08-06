class Solution {
public:
    int product(int n){
        int ans=1;
        while(n>0){
            ans*=(n%10);
            n/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t==0) return n;
            n++;
        }
    }
};