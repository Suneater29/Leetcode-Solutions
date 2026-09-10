class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> parent;
    string beginWord;
    void dfs(string word,vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, path);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList) {
        this->beginWord = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return {};
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> usedThisLevel;
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            usedThisLevel.clear();
            for (int k = 0; k < sz; k++) {
                string word = q.front();
                q.pop();
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original)
                            continue;
                        temp[i] = ch;
                        if (st.count(temp)) {
                            if (!usedThisLevel.count(temp)) {
                                q.push(temp);
                                usedThisLevel.insert(temp);
                            }
                            parent[temp].push_back(word);
                            if (temp == endWord)
                                found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            for (auto& word:usedThisLevel) st.erase(word);
        }
        if (!parent.count(endWord)) return {};
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord,path);
        return ans;
    }
};