class Solution {
public:
    long long totaltime(vector<int>& piles,int mid){
        long long sum=0;
        for(int i:piles){
            sum+=(i+mid-1)/mid;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=maxi;
        int k=maxi;
        while(low<=high){
            int mid=low+((high-low)/2);
            long long totalhours=totaltime(piles,mid);
            if(totalhours>h){
                low=mid+1;
            }
            else{
                k=mid;
                high=mid-1;
            }
        }
        return k;
    }
};