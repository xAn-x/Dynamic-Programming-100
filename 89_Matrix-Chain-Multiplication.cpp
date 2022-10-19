class Solution {
public:
    //Recursion-->
    int get_matMul(int arr[], int st, int end) {
        if (st == end) return 0;

        int ans = 1e9;
        for (int k = st; k < end; ++k) {
            int steps = (arr[st - 1] * arr[k] * arr[end]) + get_matMul(arr, st, k) + get_matMul(arr, k + 1, end);
            ans = min(steps, ans);
        }

        return ans;
    }

    int matrixMultiplication(int N, int arr[]) {
        int st = 1, end = N - 1;
        return get_matMul(arr, st, end);
    }

    //Memoization-->
    int get_matMul(int arr[], int st, int end, vector<vector<int>>&dp) {
        if (st == end) return 0;

        if (dp[st][end] != -1) return dp[st][end];

        int ans = 1e9;
        for (int k = st; k < end; ++k) {
            int steps = (arr[st - 1] * arr[k] * arr[end]) + get_matMul(arr, st, k, dp) + get_matMul(arr, k + 1, end, dp);
            ans = min(steps, ans);
        }

        return dp[st][end] = ans;
    }

    int matrixMultiplication(int N, int arr[]) {
        int st = 1, end = N - 1;
        vector<vector<int>>dp(N, vector<int>(N, -1));
        return get_matMul(arr, st, end, dp);
    }

    // Tabulation-->
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>>dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 0;
        }

        // Copy the recurence
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = st; k < end - 1; ++k) {
                    int steps = (arr[st - 1] * arr[k] * arr[end]) + dp[i][k] + dp[k + 1][j];
                    `
                }
            }
        }
        return dp[n - 1][n - 1];
    }
};