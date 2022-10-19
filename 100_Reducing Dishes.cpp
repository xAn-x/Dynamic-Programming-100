// https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    // Recursive-->
    int solve(vector<int>&satisfac, int idx, int time) {
        if (idx == satisfac.size()) return 0;

        int maxSatisfaction = 0;
        //I can choose to cook the +nt dish
        int satisfac1 = time * satisfac[idx] + solve(satisfac, idx + 1, time + 1);
        int satisfac2 = solve(satisfac, idx + 1, time);

        maxSatisfaction = max({maxSatisfaction, satisfac1, satisfac2});
        return maxSatisfaction;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        //Sort as the dishes with more satifaction should be looked as far as possible
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 1);
    }


    // Memoization-->
    int solve(vector<int>&satisfac, int idx, int time, vector<vector<int>>&dp) {
        if (idx == satisfac.size()) return 0;

        if (dp[idx][time] != -1) return dp[idx][time];

        int maxSatisfaction = 0;
        //I can choose to cook the +nt dish or leave and cook some other
        int satisfac1 = time * satisfac[idx] + solve(satisfac, idx + 1, time + 1, dp);
        int satisfac2 = solve(satisfac, idx + 1, time, dp);

        maxSatisfaction = max({maxSatisfaction, satisfac1, satisfac2});
        return dp[idx][time] = maxSatisfaction;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int len = satisfaction.size();
        vector<vector<int>>dp(len, vector<int>(len + 1, -1));
        return solve(satisfaction, 0, 1, dp);
    }

    // Tabulation-->
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int len = satisfaction.size();
        vector<vector<int>>dp(len + 1, vector<int>(len + 2, 0));

        for (int idx = len - 1; idx >= 0; --idx) {
            for (int time = len; time > 0; --time) {
                int maxSatisfaction = 0;
                //I can choose to cook the +nt dish or leave and cook some other
                int satisfac1 = time * satisfaction[idx] + dp[idx+1][time+1];
                int satisfac2 = dp[idx+1][time];

                maxSatisfaction = max({maxSatisfaction, satisfac1, satisfac2});
                dp[idx][time] = maxSatisfaction;
            }
        }

        return dp[0][1];
    }
};