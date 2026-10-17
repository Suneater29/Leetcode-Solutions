
class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    bool comp(pair<int, int> a, pair<int, int> b) {
        int sumA = digitSum(a.first);
        int sumB = digitSum(b.first);
        if (sumA != sumB)
            return sumA < sumB;
        return a.first < b.first;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(),[this](pair<int, int> a, pair<int, int> b) {
                 return comp(a, b);
        });
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }
            swaps += cycleSize - 1;
        }
        return swaps;
    }
};
