// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
    int mod=1e9+7;
public:
    //Recursion-->
    int solve(int n,int k,int target){
        if(n < 0) return 0;
        if(target < 0) return 0;
        if(target == 0 and n == 0) return 1;
        if(target == 0 and n != 0 ) return 0;
        if(n == 0 and target != 0) return 0;
        
        //for nth dice I have k choices->
        int tot_ways=0;
        for(int i=1;i<=k;++i){
            tot_ways=(tot_ways%mod+solve(n-1,k,target-i)%mod)%mod;
        }
        return tot_ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }

    //Memoization-->
    int solve(int n,int k,int target,vector<vector<int>>&dp){
        if(n < 0) return 0;
        if(target < 0) return 0;
        if(target == 0 and n == 0) return 1;
        if(target == 0 and n != 0 ) return 0;
        if(n == 0 and target != 0) return 0;

        
        if(dp[n][target]!=-1) return dp[n][target];
        //for nth dice I have k choices->
        int tot_ways=0;
        for(int i=1;i<=k;++i){
            tot_ways=(tot_ways%mod+(solve(n-1,k,target-i,dp)%mod))%mod;
        }
        return dp[n][target]=(tot_ways%mod);
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }

    // Tabulation-->
    int numRollsToTarget(int n, int k, int target) {
        if(target < 0) return 0;
        if(target == 0 and n == 0) return 1;
        if(target == 0 and n != 0 ) return 0;
        if(n == 0 and target != 0) return 0;

        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;

        for(int i=1;i<=n;++i){
            for(int j=1;j<=target;++j){
                int tot_ways=0;
                for(int l=1;l<=j and l<=k;++l){
                    tot_ways=(tot_ways%mod + (dp[i-1][j-l]%mod))%mod;
                }
                dp[i][j]=max(dp[i][j],tot_ways);
            }
        }
        return dp[n][target];
    }
};