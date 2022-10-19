class Solution {
public:
    //Recursion
    int helper(int num,int target){
        if(target==0) return 0;
        if(target<0) return 1e9;
        if(num*num>target) return 1e9;
        
        //if i decide to go with same perfect sqr
        int cnt1=1+helper(num,target-num*num);
        
        //if i decide to go with next perfect sqr
        int cnt2=helper(num+1,target);
        
        return min(cnt1,cnt2);
    }
    
    int numSquares(int n) {
        return helper(1,n);
    }


    //Memoization
    int helper(int num,int target,vector<vector<int>>&dp){
        if(target==0) return 0;
        if(target<0) return 1e9;
        if(num*num>target) return 1e9;
        
        if(dp[num][target]!=-1) return dp[num][target];

        //if i decide to go with same perfect sqr
        int cnt1=1+helper(num,target-num*num,dp);
        
        //if i decide to go with next perfect sqr
        int cnt2=helper(num+1,target,dp);
        
        return dp[num][target]=min(cnt1,cnt2);
    }

    int numSquares(int n) {
        int sqroot=sqrt(n);
        vector<vector<int>>dp(sqroot+1,vector<int>(n+1,-1));
        return helper(1,n,dp);
    }


//--------------------- Method-2 ------------------------------->
    // Recursion
    int helper(int target){
        if(target==0) return 0;
        if(target<0) return 1e9;

        int cnt=1e9;
        for(int i=1;i*i<=target;++i){
            cnt=min(cnt,1+helper(target-i*i));
        }

        return cnt;
    }

    int numSquares(int target) {
        return helper(target);
    }



    //Memoization
    int helper(int target,vector<int>&dp){
        if(target==0) return 0;
        if(target<0) return 1e9;

        if(dp[target]!=-1) return dp[target];

        int cnt=1e9;
        for(int i=1;i*i<=target;++i){
            cnt=min(cnt,1+helper(target-i*i,dp));
        }

        return dp[target]=cnt;
    }

    int numSquares(int target) {
        vector<int>dp(target+1,-1);
        return helper(target,dp);
    }


    // Tabulation
    int numSquares(int target){
        vector<int>dp(target+1,1e9);
        dp[0]=0;

        for(int i=1;i<=target;++i){
            int cnt=1e9;
            for(int j=1;j*j<=i;++j){
                cnt=min(cnt,1+dp[i-j*j]);
            }
            dp[i]=cnt;
        }

        return dp[target];
    }
}; 