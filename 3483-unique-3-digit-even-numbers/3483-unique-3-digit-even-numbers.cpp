class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }
        int count = 0;
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100;    
            int d2 = (i / 10) % 10;
            int d3 = i % 10;        
            vector<int> current_freq(10, 0);
            current_freq[d1]++;
            current_freq[d2]++;
            current_freq[d3]++;
            if (freq[d1] >= current_freq[d1] &&
                freq[d2] >= current_freq[d2] &&
                freq[d3] >= current_freq[d3]) {
                count++;
            }
        }
        return count;
    }
};