class Solution {
public:
    void generate(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &curr,int index,int target){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[index]<=target){
            curr.push_back(candidates[index]);
            generate(candidates,ans,curr,index,target-candidates[index]);
            curr.pop_back();
        }
        generate(candidates,ans,curr,index+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        generate(candidates,ans,curr,0,target);
        return ans;
    }
};