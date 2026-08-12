class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int strt=0;
        int len=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp[nums[i]]>k){
                mpp[nums[strt]]--;
                strt++;
            }
            len=max(len,i-strt+1);
        }
        return len;
    }
};