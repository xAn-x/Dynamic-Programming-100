// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
class Solution{
    int MOD=1e9+7;
    public:
    long long countWays(int n, int k){
        if(k==0) return 0;
        
        if(n==1) return k;
        else if(n==2) return (k%MOD * k%MOD)%MOD;


        // if last 2 fence has same col
        long long same=( (k-1)%MOD*countWays(n-2,k)%MOD )%MOD;

        // if last 2 fence has diff col
        long long diff=( (k-1)%MOD*countWays(n-1,k)%MOD)%MOD;

        long long tot_ways=(same%MOD+diff%MOD)%MOD;
        return tot_ways;
    }


    // --------- MEMOIZATION ----------->
    long long helper(int n, int k,int dp[]){
        if(k==0) return 0;
        
        if(n==1) return k;
        else if(n==2) return (k%MOD * k%MOD)%MOD;

        if(dp[n]!=-1) return dp[n];

        // if last 2 fence has same col
        long long same=( (k-1)%MOD*helper(n-2,k,dp)%MOD )%MOD;

        // if last 2 fence has diff col
        long long diff=( (k-1)%MOD*helper(n-1,k,dp)%MOD)%MOD;

        long long tot_ways=(same%MOD+diff%MOD)%MOD;
        return dp[n]=tot_ways;
    }

    long long countWays(int n,int k){
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return helper(n,k,dp);
    }


// ------------ TABULATION ---------->
    long long countWays(int n,int k){
        if(k==0) return 0;
        
        if(n==1) return k;
        else if(n==2) return (k%MOD*k%MOD)%MOD;

        long long dp[n+1];
        
        dp[1]=k; dp[2]=(k%MOD*k%MOD)%MOD;        
        for(int i=3;i<=n;++i){
            dp[i]=((k-1)%MOD*(dp[i-1]%MOD+dp[i-2]%MOD)%MOD)%MOD;
        }
        return dp[n];
    }

};