class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>sortedpair(n);
        for(int i=0;i<n;i++){
            sortedpair[i]={nums[i],i};
        }
        sort(sortedpair.begin(),sortedpair.end());
        vector<int>ans(n);
        int index=0;
        while(index<n){
            int i=index;
            while(i+1<n && sortedpair[i+1].first-sortedpair[i].first<=limit){
                i++;
            }
            vector<int>indices;
            for(int j=index;j<=i;j++){
                indices.push_back(sortedpair[j].second);
            }
            sort(indices.begin(),indices.end());
            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=sortedpair[index+k].first;
            }
            index=i+1;
        }
        return ans;
    }
};