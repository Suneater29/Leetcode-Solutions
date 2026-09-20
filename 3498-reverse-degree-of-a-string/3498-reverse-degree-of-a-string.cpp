class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int pos=26-(s[i]-'a');
            int index=i+1;
            sum+=pos*index;
        }
        return sum;
    }
};