// https://leetcode.com/problems/russian-doll-envelopes/

// LIS-Variation
class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        else {
            return a[0] < b[0];
        }
    }
public:
    // Simple LIS-->
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        int len = envelopes.size(), maxEnv = 1;
        vector<int>dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            maxEnv = max(maxEnv, dp[i]);
        }
        return maxEnv;
    }


    // LIS + Binary-Search=>
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // step 1: sort the 2d array by row and if same row comes, sort by col in decreasing order
        sort(envelopes.begin(), envelopes.end(), cmp);

        // step 2: apply DP with binary search
        int n = envelopes.size();
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > ans.back())
                ans.push_back(envelopes[i][1]);
            else {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};