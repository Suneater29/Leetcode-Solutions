class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        int ans=0;
        int end=-1;
        for(int i=0;i<2*n-1;i++){
            int left=i/2;
            int right=left+(i%2);
            while(left>=0 && right<n && s[left]==s[right]){
                int size=right-left+1;
                if(size>=k){
                    if(left>end){
                        ans++;
                        end=right;
                    }
                    break;
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};