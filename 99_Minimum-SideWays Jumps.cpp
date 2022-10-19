class Solution {
public:
    // Recursive
    int minJumps(vector<int>&obs, int src, int dest, int lane) {
        if (src == dest) return 0;

        //Can i go straight-->
        if (obs[src + 1] != lane) return minJumps(obs, src + 1, dest, lane);

        //Else Make Sideways jump if pos->
        int min_jumps = 1e9;
        for (int i = 1; i <= 3; ++i) {
            //Dant make sideway jump to same lane or in lane with obstacle
            if (i == lane or obs[src] == i) continue;
            int jumps = 1 + minJumps(obs, src, dest, i);
            min_jumps = min(min_jumps, jumps);
        }
        return min_jumps;
    }

    int minSideJumps(vector<int>& obstacles) {
        int src = 0, dest = obstacles.size() - 1, lane = 2;
        return minJumps(obstacles, src, dest, lane);
    }

    // Memoization
    int minJumps(vector<int>&obs, int src, int dest, int lane, vector<vector<int>>&dp) {
        if (src == dest) return 0;

        if (dp[src][lane] != -1) return dp[src][lane];

        //Can i go straight-->
        if (obs[src + 1] != lane) return dp[src][lane] = minJumps(obs, src + 1, dest, lane, dp);

        //Else Make Sideways jump if pos->
        int min_jumps = 1e9;
        for (int i = 1; i <= 3; ++i) {
            //Dant make sideway jump to same lane or in lane with obstacle
            if (i == lane or obs[src] == i) continue;
            int jumps = 1 + minJumps(obs, src, dest, i, dp);
            min_jumps = min(min_jumps, jumps);
        }
        return dp[src][lane] = min_jumps;
    }

    int minSideJumps(vector<int>& obstacles) {
        int src = 0, dest = obstacles.size() - 1, lane = 2;
        vector<vector<int>>dp(dest + 1, vector<int>(4, -1));
        return minJumps(obstacles, src, dest, lane, dp);
    }
};