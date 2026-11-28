class Solution {
public:
    bool partitionSum(int ind,vector<int> &nums,int target,int n){
        vector<bool>prev(target+1,false);
        vector<bool>curr(target+1,false);
        prev[0]=true;
        if(nums[0]<=target){
            prev[nums[0]]=true;
        }
        for(int ind=1;ind<n;ind++){
            curr[0]=true;
            for(int k=1;k<=target;k++){
                bool notTake=prev[k];
                bool take=false;
                if(nums[ind]<=k){
                    take=prev[k-nums[ind]];
                }
                curr[k]=take || notTake;
            }
            prev=curr;
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        int ans=partitionSum(n-1,nums,target,n);
        return ans;
    }
};