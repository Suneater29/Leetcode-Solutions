class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {
                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string result = ans;
                        result += char('a' + c);
                        freq[c]--;
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                result += char('a' + k);
                                freq[k]--;
                            }
                        }
                        return result;
                    }
                }
                for (int j = i - 1; j >= 0; j--) {
                    freq[ans[j] - 'a']++;
                    int current = ans[j] - 'a';
                    for (int c = current + 1; c < 26; c++) {
                        if (freq[c] > 0) {
                            string result = ans.substr(0, j);
                            result += char('a' + c);
                            freq[c]--;
                            for (int k = 0; k < 26; k++) {
                                while (freq[k] > 0) {
                                    result += char('a' + k);
                                    freq[k]--;
                                }
                            }
                            return result;
                        }
                    }
                }
                return "";
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            freq[ans[i] - 'a']++;
            int current = ans[i] - 'a';
            for (int c = current + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = ans.substr(0, i);
                    result += char('a' + c);
                    freq[c]--;
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            result += char('a' + k);
                            freq[k]--;
                        }
                    }
                    return result;
                }
            }
        }
        return "";
    }
};