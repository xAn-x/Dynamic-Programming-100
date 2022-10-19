// Given a vector of ints and a target task is tell weather any subarray with sum=target sum exist or not

class Solution{
public:
    //Recursion->O(2^n)
    bool targetSum_subset(vector<int>&nums,int n,int target){
        if(n==0) return target==0;
        else if(target<0) return false;

        return targetSum_subset(nums,n-1,target) or targetSum_subset(nums,n-1,target-nums[n-1]);
    }

    bool targetSum_subset(vector<int>&nums,int n,int target,vector<vector<int>>&dp){
        if(n==0) return target==0;
        else if(target<0) return false;

        if(dp[n][target]!=-1) return dp[target][n-1];
        return dp[n][target]=targetSum_subset(nums,n-1,target) or targetSum_subset(nums,n-1,target-nums[n-1]);
    }

    bool targetSum_subset(vector<int>&nums,int target){
        int n=nums.size();
        //Plain-Recursion
        return targetSum_subset(nums,n,target);

        //Memoization
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return targetSum_subset(nums,n,target,dp);

        //Tabulation + space-optimisation
        vector<bool>prv(target+1),curr(target+1);
        prv[0]=curr[0]=true;

        for(int i=1;i<=n;++i){
            for(int s=0;s<=target;++s){
                if(nums[i-1]>s) curr[s]=prv[s];
                else curr[s]=prv[s] or prv[s-nums[i-1]];
            }
            prv=curr;
        }
        return prv[target];
    }
};