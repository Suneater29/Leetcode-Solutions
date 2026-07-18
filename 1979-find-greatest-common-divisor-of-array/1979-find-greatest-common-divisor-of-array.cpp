class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=nums[0];
        int high=nums[n-1];
        return gcd(low,high);
    }
};