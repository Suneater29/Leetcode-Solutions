class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return (nums[n-1]-1)*(nums[n-2]-1);
        int max1=0;
        int max2=0;
        for(int i:nums){
            if(i>=max1){
                max2=max1;
                max1=i;
            }
            else if(i>max2){
                max2=i;
            }
        }
        return (max1-1)*(max2-1);
    }
};