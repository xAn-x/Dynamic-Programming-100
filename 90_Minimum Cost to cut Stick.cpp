// https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
class Solution {
public:
    // Recursion-->
    int func(vector<int>&cuts, int st_idx, int end_idx, int st, int end) {
        if (st_idx > end_idx) return 0;

        int min_price = 1e9;
        for (int k = st_idx; k <= end_idx; ++k) {
            int price = (end - st) + func(cuts, st_idx, k - 1, st, cuts[k]) + func(cuts, k + 1, end_idx, cuts[k], end);
            min_price = min(min_price, price);
        }
        return min_price;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return func(cuts, 0, cuts.size() - 1, 0, n);
    }

    // Memoization-->
    int func(vector<int>&cuts, int st_idx, int end_idx, int st, int end, vector<vector<int>>&dp) {
        if (st_idx > end_idx) return 0;

        if (dp[st_idx][end_idx] != -1) return dp[st_idx][end_idx];

        int min_price = 1e9;
        for (int k = st_idx; k <= end_idx; ++k) {
            //len
            int price = (end - st) + func(cuts, st_idx, k - 1, st, cuts[k], dp) + func(cuts, k + 1, end_idx, cuts[k], end, dp);
            min_price = min(min_price, price);
        }
        return dp[st_idx][end_idx] = min_price;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        int len = cuts.size();
        vector<vector<int>>dp(len, vector<int>(len, -1));
        return func(cuts, 0, len - 1, 0, n, dp);
    }
};