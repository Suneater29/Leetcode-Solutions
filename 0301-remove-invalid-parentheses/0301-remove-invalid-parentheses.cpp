class Solution {
private:
    unordered_set<string> resultSet;
    void dfs(const string& s, int index, int remL, int remR, int balance, string current) {
        if (balance < 0) return;
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && balance == 0) {
                resultSet.insert(current);
            }
            return;
        }
        char ch = s[index];
        if (ch == '(') {
            if (remL > 0) {
                dfs(s, index + 1, remL - 1, remR, balance, current);
            }
            dfs(s, index + 1, remL, remR, balance + 1, current + ch);
        } 
        else if (ch == ')') {
            if (remR > 0) {
                dfs(s, index + 1, remL, remR - 1, balance, current);
            }
            dfs(s, index + 1, remL, remR, balance - 1, current + ch);
        } 
        else {
            dfs(s, index + 1, remL, remR, balance, current + ch);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        for (char ch : s) {
            if (ch == '(') {
                remL++;
            } else if (ch == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }
        resultSet.clear();
        dfs(s, 0, remL, remR, 0, "");
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};