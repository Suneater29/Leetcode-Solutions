class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int odd_cnt = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                mid_char = 'a' + i;
            }
        }
        if (odd_cnt > 1) return "";
        int m = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }
        string best_res = "";
        auto make_palindrome = [&](const string& half, char mid) -> string {
            string rev_half = half;
            reverse(rev_half.begin(), rev_half.end());
            if (n % 2 != 0) {
                return half + mid + rev_half;
            } else {
                return half + rev_half;
            }
        };
        auto can_form_prefix = [&](int len) -> bool {
            vector<int> req(26, 0);
            for (int j = 0; j < len; ++j) {
                req[target[j] - 'a']++;
            }
            for (int c = 0; c < 26; ++c) {
                if (req[c] > half_count[c]) return false;
            }
            return true;
        };
        for (int i = m; i >= 0; --i) {
            if (!can_form_prefix(i)) continue;
            vector<int> rem_count = half_count;
            for (int j = 0; j < i; ++j) {
                rem_count[target[j] - 'a']--;
            }
            string pref = target.substr(0, i);
            if (i == m) {
                if (n % 2 != 0) {
                    if (mid_char > target[m]) {
                        string cand = make_palindrome(pref, mid_char);
                        if (cand > target) {
                            if (best_res == "" || cand < best_res) best_res = cand;
                        }
                    } else if (mid_char == target[m]) {
                        string cand = make_palindrome(pref, mid_char);
                        if (cand > target) {
                            if (best_res == "" || cand < best_res) best_res = cand;
                        }
                    }
                } else {
                    string cand = make_palindrome(pref, 0);
                    if (cand > target) {
                        if (best_res == "" || cand < best_res) best_res = cand;
                    }
                }
            } else {
                for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                    if (rem_count[c] > 0) {
                        vector<int> cur_rem = rem_count;
                        cur_rem[c]--;
                        string cur_half = pref;
                        cur_half.push_back('a' + c);
                        for (int k = 0; k < 26; ++k) {
                            while (cur_rem[k] > 0) {
                                cur_half.push_back('a' + k);
                                cur_rem[k]--;
                            }
                        }
                        string cand = make_palindrome(cur_half, mid_char);
                        if (cand > target) {
                            if (best_res == "" || cand < best_res) best_res = cand;
                        }
                        break;
                    }
                }
            }
            if (best_res != "") break;
        }
        return best_res;
    }
};