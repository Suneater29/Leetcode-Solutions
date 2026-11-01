class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=nums[i]-mini;
        }
        return sum;
    }
};