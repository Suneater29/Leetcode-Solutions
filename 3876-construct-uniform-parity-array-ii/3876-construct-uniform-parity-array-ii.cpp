class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=nums1[0];
        bool isodd=false;
        for(int i:nums1){
            if(i<mini){
                mini=i;
            }
            if(i%2!=0){
                isodd=true;
            }
        }
        if(mini%2!=0) return true;
        return !isodd;
    }
};