// class Solution {
// public:
//     int sortableIntegers(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> fac;
//         for (int x = 1; x * x <= n; ++x) {
//             if (n % x == 0) {
//                 fac.push_back(x);
//                 if (n / x != x) {
//                     fac.push_back(n / x);
//                 }
//             }
//         }
//         vector<int> target = nums;
//         sort(target.begin(),target.end());
//         auto kmp = [](const vector<int>& nums1, const vector<int>& nums2) {
//             int n = nums1.size(), m = nums2.size();
//             vector<int> pi(m, 0);
//             int j = 0;
//             for (int i = 1; i < m; ++i) {
//                 while (j > 0 && nums2[i] != nums2[j]) {
//                     j = pi[j - 1];
//                 }
//                 if (nums2[i] == nums2[j]) {
//                     ++j;
//                 }
//                 pi[i] = j;
//             }
//             j = 0;
//             for (int i = 0; i < n; ++i) {
//                 while (j > 0 && nums1[i] != nums2[j]) {
//                     j = pi[j - 1];
//                 }
//                 if (nums1[i] == nums2[j]) {
//                     ++j;
//                 }
//                 if (j == m) {
//                     return true;
//                 }
//             }
//             return false;
//         };

//         auto check = [&](const vector<int>& nums1, const vector<int>& nums2)
//         {
//             vector<int> doubled = nums1;
//             doubled.insert(doubled.end(), nums1.begin(), nums1.end());
//             return kmp(doubled, nums2);
//         };
//         int ans = 0;
//         for (int d : fac) {
//             bool allGood = true;
//             for (int left = 0; left < n; left += d) {
//                 int right = left + d - 1;
//                 vector<int> sub1(nums.begin() + left, nums.begin() + right +
//                 1); vector<int> sub2(target.begin() + left,target.begin() +
//                 right + 1);

//                 if (!check(sub1, sub2)) {
//                     allGood = false;
//                     break;
//                 }
//             }
//             if (allGood) {
//                 ans += d;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool isRotation(const vector<int>& a, const vector<int>& b) {
        int k = a.size();
        int j = 0;
        vector<int> pi(k, 0);
        for (int i = 1; i < k; i++) {
            while (j > 0 && b[i] != b[j])
                j = pi[j - 1];
            if (b[i] == b[j])
                j++;
            pi[i] = j;
        }
        j = 0;
        for (int i = 0; i < 2 * k - 1; i++) {
            int x = a[i % k];
            while (j > 0 && x != b[j])
                j = pi[j - 1];
            if (x == b[j])
                j++;
            if (j == k)
                return true;
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(target.begin(), target.end());
        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d != n / d)
                    divisors.push_back(n / d);
            }
        }
        int ans = 0;
        for (int k : divisors) {
            bool valid = true;
            for (int l = 0; l < n; l += k) {
                vector<int> a(nums.begin() + l, nums.begin() + l + k);
                vector<int> b(target.begin() + l, target.begin() + l + k);

                if (!isRotation(a, b)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans += k;
        }
        return ans;
    }
};
