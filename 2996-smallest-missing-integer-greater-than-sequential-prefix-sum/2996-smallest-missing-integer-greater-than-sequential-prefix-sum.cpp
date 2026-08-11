class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int presum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                presum+=nums[i];
            }
            else break;
        }
        set<int>st(nums.begin(),nums.end());
        while(st.count(presum)){
            presum++;
        }
        return presum;
    }
};