class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixgcd;
        int mx=0;
        for(int i:nums){
            mx=max(mx,i);
            prefixgcd.push_back(gcd(i,mx));
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum=0;
        int low=0;
        int high=n-1;
        while(low<high){
            sum+=gcd(prefixgcd[low],prefixgcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};