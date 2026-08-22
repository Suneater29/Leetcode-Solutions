class Solution {
public:
    bool checkDivisibility(int n) {
        int given=n;
        int sum=0;
        int product=1;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            product*=digit;
            n/=10;
        }
        int total=sum+product;
        if(given%total==0) return true;
        return false;
    }
};