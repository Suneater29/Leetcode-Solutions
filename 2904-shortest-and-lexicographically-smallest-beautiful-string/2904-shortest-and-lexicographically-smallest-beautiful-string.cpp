class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones = 0;
        int left = 0;
        string ans = "";
        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                ones++;
            }
            while (ones == k) {
                while (s[left] == '0') {
                    left++;
                }
                string candidate = s.substr(left, right - left + 1);
                if (ans.empty() || candidate.length() < ans.length() || 
                   (candidate.length() == ans.length() && candidate < ans)) {
                    ans = candidate;
                }
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }
        }
        return ans;
    }
};