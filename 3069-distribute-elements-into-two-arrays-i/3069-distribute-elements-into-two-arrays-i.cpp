class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n=nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1.back()>arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int>result;
        for(auto it:arr1){
            result.push_back(it);
        }
        for(auto it:arr2){
            result.push_back(it);
        }
        return result;
    }
};