// https://leetcode.com/problems/pizza-with-3n-slices/

class Solution {
public:
    //Recursive-->
    int solve(vector<int>&slices, int idx, int end, int n) {
        if (idx > end or n == 0) return 0;

        //Note I don't have to care about anticlock wise stuff as it will be handeled because of the 2cases just move ahead

        //I can eat the present slice
        int take = slices[idx] + solve(slices, idx + 2, end, n - 1);
        int not_take = 0 + solve(slices, idx + 1, end, n);

        return max(take, not_take);
    }


    int maxSizeSlices(vector<int>& slices) {
        //Note: Either i can eat first flice or i can eat last slice I can't eat both so decide what to do

        int len = slices.size(), n = len / 3;

        //Eat first
        int case1 = solve(slices, 0, len - 2, n);

        //Eat last
        int case2 = solve(slices, 1, len - 1, n);

        return max(case1, case2);
    }


    //Memoization-->
    int solve(vector<int>&slices, int idx, int end, int n, vector<vector<int>>&dp) {
        if (idx > end or n == 0) return 0;

        //Note I don't have to care about anticlock wise stuff as it will be handeled because of the 2cases just move ahead
        if (dp[idx][n] != -1) return dp[idx][n];

        //I can eat the present slice
        int take = slices[idx] + solve(slices, idx + 2, end, n - 1, dp);
        int not_take = 0 + solve(slices, idx + 1, end, n, dp);

        return dp[idx][n] = max(take, not_take);
    }


    int maxSizeSlices(vector<int>& slices) {
        //Note: Either i can eat first flice or i can eat last slice I can't eat both so decide what to do

        int len = slices.size(), n = len / 3;
        vector<vector<int>>dp(len, vector<int>(n + 1, -1));

        //Eat first
        int case1 = solve(slices, 0, len - 2, n, dp);


        //Eat last
        for (vector<int>&v : dp) fill(v.begin(), v.end(), -1);
        int case2 = solve(slices, 1, len - 1, n, dp);

        return max(case1, case2);
    }

     // Tabulation-->
    int solve(vector<int>&slices,int st,int end) {
        int len = slices.size(), n = len / 3;
        vector<vector<int>>dp(len + 3, vector<int>(n + 1, 0));

        //Base-case
        for (int idx = end; idx >= st; idx--) {
            for (int slice = 1; slice <= n; ++slice) {
                int take = slices[idx] + dp[idx+2][slice-1];
                int not_take = 0 + dp[idx+1][slice];
                
                dp[idx][slice]=max(take,not_take);
            }
        }

        return dp[st][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        //Note: Either i can eat first flice or i can eat last slice I can't eat both so decide what to do
        
        int len = slices.size();
        //Eat first
        int case1 = solve(slices, 0, len - 2);


        //Eat last
        int case2 = solve(slices, 1, len - 1);

        return max(case1, case2);
    }
};