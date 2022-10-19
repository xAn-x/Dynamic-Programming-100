// https://leetcode.com/problems/super-egg-drop/
class Solution {
public:
    //Recursive-->
    int solve(int st, int end, int egg_cnt) {
        //Then in worst case I have to check all floors
        if (egg_cnt == 1) return end - st + 1;

        //If no of floors are 0/1 then in worst case I need to check f floor
        if (st == end) return 1;
        if (st > end) return 0;


        //For each floor in the building chk the worstcase
        int minAttempts = 1e9;
        for (int k = st; k <= end; ++k) {
            //If egg-brokes chk floors below k
            int attm1 = 1 + solve(st, k - 1, egg_cnt - 1);

            //iF egg doesn't break chk floor above k
            int attm2 = 1 + solve(k + 1, end, egg_cnt);

            //Since I need to minimize the worst-case
            minAttempts = min(minAttempts, max(attm1, attm2));
        }
        return minAttempts;
    }

    int superEggDrop(int k, int n) {
        return solve(1, n, k);
    }


    // Memoization-->
    int solve(int st, int end, int egg_cnt, vector<vector<vector<int>>>&dp) {
        //Then in worst case I have to check all floors
        if (egg_cnt == 1) return end - st + 1;

        //If no of floors are 0/1 then in worst case I need to check f floor
        if (st == end) return 1;
        if (st > end) return 0;

        if (dp[st][end][egg_cnt] != -1) return dp[st][end][egg_cnt];

        //For each floor in the building chk the worstcase
        int minAttempts = 1e9;
        for (int k = st; k <= end; ++k) {
            //If egg-brokes chk floors below k
            int attm1 = 1 + solve(st, k - 1, egg_cnt - 1, dp);

            //iF egg doesn't break chk floor above k
            int attm2 = 1 + solve(k + 1, end, egg_cnt, dp);

            //Since I need to minimize the worst-case
            minAttempts = min(minAttempts, max(attm1, attm2));
        }
        return dp[st][end][egg_cnt] = minAttempts;
    }

    int superEggDrop(int k, int n) {
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(1, n, k, dp);
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WAY-2~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //Recursive-->
    int solve(int egg_cnt, int floor_cnt) {
        //Then in worst case I have to check all floors
        if (egg_cnt == 1) return floor_cnt;

        //If no of floors are 0/1 then in worst case I need to check f floor
        if (floor_cnt<=1) return floor_cnt;

        //For each floor in the building chk the worstcase
        int minAttempts = 1e9;
        for (int k =1; k <= floor_cnt; ++k) {
            //If egg-brokes chk floors below k
            int attm1 = 1 + solve(egg_cnt-1,k-1);

            //iF egg doesn't break chk floor above k
            int attm2 = 1 + solve(egg_cnt,floor_cnt-k);

            //Since I need to minimize the worst-case
            minAttempts = min(minAttempts, max(attm1, attm2));
        }
        return minAttempts;
    }

    int superEggDrop(int k, int n) {
        return solve(k,n);
    }


    // Memoization-->
    int solve(int egg_cnt, int floor_cnt,vector<vector<int>>&dp) {
        //Then in worst case I have to check all floors
        if (egg_cnt == 1) return floor_cnt;

        //If no of floors are 0/1 then in worst case I need to check f floor
        if (floor_cnt<=1) return floor_cnt;

        if(dp[egg_cnt][floor_cnt]!=-1) return dp[egg_cnt][floor_cnt];

        //For each floor in the building chk the worstcase
        int minAttempts = 1e9;
        for (int k =1; k <= floor_cnt; ++k) {
            //If egg-brokes chk floors below k
            int attm1 = 1 + solve(egg_cnt-1,k-1,dp);

            //iF egg doesn't break chk floor above k
            int attm2 = 1 + solve(egg_cnt,floor_cnt-k,dp);

            //Since I need to minimize the worst-case
            minAttempts = min(minAttempts, max(attm1, attm2));
        }
        return dp[egg_cnt][floor_cnt]=minAttempts;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }


    // DP+Binary-Search
    int dp[101][10001];
    int solve(int k,int n){
        if(n == 0 || n == 1 || k == 1)return dp[k][n] = n;
        if(dp[k][n] != -1)return dp[k][n];
        int mn = INT_MAX,low = 1,high = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            int a = solve(k-1,mid-1);
            int b = solve(k,n-mid);
            mn = min(mn,1+max(a,b));
            if(a > b)
                high = mid-1;
            else
                low = mid+1;
        }
        return dp[k][n] = mn;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};