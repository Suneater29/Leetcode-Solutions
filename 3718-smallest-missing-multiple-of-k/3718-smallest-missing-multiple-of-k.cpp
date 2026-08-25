class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=k;
        for(int i:nums){
            if(i==ans){
                ans+=k;
            }
        }
        return ans;
    }
};