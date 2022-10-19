int mod=(int)1e9+7;

//Plain-Recursion->O(2^n)
/*
int countPartitions(vector<int>&nums,int n,int d,int sum,int totSum){
    if(n==0){
        return ((totSum-2*sum)==d)?1:0;
    }
    return (countPartitions(nums,n-1,d,sum,totSum,dp)%mod + countPartitions(nums,n-1,d,sum+nums[n-1],totSum,dp)%mod)%mod;
}
*/


int countPartitions(vector<int>&nums,int n,int d,int sum,int totSum,vector<vector<int>>&dp){
    if(n==0){
        return ((totSum-2*sum)==d)?1:0;
    }
    if(dp[n][sum]!=-1) return dp[n][sum];
    return dp[n][sum]=(countPartitions(nums,n-1,d,sum,totSum,dp)%mod + countPartitions(nums,n-1,d,sum+nums[n-1],totSum,dp)%mod)%mod;
}


int countPartitions(int n, int d, vector<int> &nums) {
    int totSum=0;
    for(int &ele:nums) totSum+=ele;

     //Plain recursion   
    // return countPartitions(nums,n,d,0,totSum); 
    

    // Memoization
    vector<vector<int>>dp(n+1,vector<int>(totSum+1,-1));   
    return countPartitions(nums,n,d,0,totSum,dp);

    /*Note->
        s1+s2=totSum --i   and    s1-s2=diff --ii
        add i and ii
        s1=(totSum+diff)/2 so find count of subset whose sum = this
    */

    //Tabulation + space-optimisation->
    int sum=(totSum+d)/2;
     vector<int>prv(sum+1),curr(sum+1);
     prv[0]=curr[0]=1;

     for(int r=1;r<=n;++r){
        for(int s=0;s<=sum;++s){
            if(nums[r-1]>s) curr[s]=prv[s]%mod;
            else curr[s]=(prv[s]%mod+prv[s-nums[r-1]]%mod)%mod;
        }
         prv=curr;
     }

     return prv[sum]%mod;
}




