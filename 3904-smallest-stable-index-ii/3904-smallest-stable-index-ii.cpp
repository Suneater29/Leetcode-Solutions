class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int>suffMin(n);
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(nums[i],suffMin[i+1]);
        }
        int curr=nums[0];
        for(int i=0;i<n;i++){
            curr=max(curr,nums[i]);
            if(curr-suffMin[i]<=k) return i;
        }
        return -1;
    }
};