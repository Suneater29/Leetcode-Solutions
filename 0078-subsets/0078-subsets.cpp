class Solution {
public:
    void generate(vector<int> &nums, vector<vector<int>> &ans,int index,vector<int>& curr){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        generate(nums,ans,index+1,curr);
        curr.push_back(nums[index]);
        generate(nums,ans,index+1,curr);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        generate(nums,ans,0,curr);
        return ans;
    }
};