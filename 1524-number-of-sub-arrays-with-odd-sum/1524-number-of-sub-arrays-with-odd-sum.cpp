class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd=0;
        long long even=1;
        long long total=0;
        long long curr=0;
        long long mod=1e9+7;
        for(int i:arr){
            curr+=i;
            if(curr%2==0){
                total=(total+odd)%mod;
                even++;
            }
            else{
                total=(total+even)%mod;
                odd++;
            }
        }
        return total;
    }
};