class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=nums[n-1];
        int ans=0;
        for(int i:nums){
            ans+=maxi-i;
        }
        return ans;
    }
};