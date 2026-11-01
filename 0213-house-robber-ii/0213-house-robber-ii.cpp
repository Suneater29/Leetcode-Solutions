class Solution {
public:
    int robbing(vector<int> &nums,int n,int start){
        int prev1=0;
        int prev2=0;
        for(int i=start;i<=n;i++){
            int take=nums[i]+prev2;
            int leave=prev1;
            int curr=max(leave,take);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int takeFirst=robbing(nums,n-2,0);
        int takeLast=robbing(nums,n-1,1);
        return max(takeFirst,takeLast);
    }
};