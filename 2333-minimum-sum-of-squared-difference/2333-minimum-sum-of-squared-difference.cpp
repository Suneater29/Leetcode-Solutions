class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        map<int, long long, greater<int>> diffCount;
        long long initialSum = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            if (d > 0) {
                diffCount[d]++;
            }
            initialSum += d;
        }
        if (initialSum <= totalK) {
            return 0;
        }
        for (auto it = diffCount.begin(); it != diffCount.end() && totalK > 0; ++it) {
            int curr = it->first;
            long long count = it->second;
            auto nextIt = std::next(it);
            int nextVal = (nextIt != diffCount.end()) ? nextIt->first : 0;
            long long diffDrop = curr - nextVal;
            long long totalCanReduce = diffDrop * count;
            if (totalK >= totalCanReduce) {
                totalK -= totalCanReduce;
                diffCount[nextVal] += count;
                it->second = 0;
            } else {
                long long steps = totalK / count;
                long long remainder = totalK % count;
                long long newTarget = curr - steps;
                it->second = 0;
                if (steps > 0) {
                    diffCount[newTarget] += count;
                } else {
                    diffCount[curr] += count;
                }
                if (remainder > 0) {
                    diffCount[newTarget - 1] += remainder;
                    diffCount[newTarget] -= remainder;
                }
                totalK = 0;
            }
        }
        long long ans = 0;
        for (auto& [val, count] : diffCount) {
            if (count > 0) {
                ans += (long long)val * val * count;
            }
        }
        return ans;
    }
};