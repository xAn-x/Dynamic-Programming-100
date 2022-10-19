// https://leetcode.com/problems/coin-change-2/
class Solution {
	int count_ways(int amount,vector<int>&coins,int n){
		if(amount==0) return 1;
		else if(amount<0 or n==0) return 0;

		return count_ways(amount,coins,n-1)+count_ways(amount-coins[n-1],coins,n);
	}

	int count_ways(int amount,vector<int>&coins,int n,dp){
		if(amount==0) return 1;
		else if(amount<0 or n==0) return 0;

		if(dp[n][amount]!=-1) return dp[n][amount];
		return dp[n][amount]=count_ways(amount,coins,n-1,dp)+count_ways(amount-coins[n-1],coins,n,dp);
	}

public:
    int change(int amount, vector<int>& coins) {
    	int n=coins.size();
        // recursion->
        // return count_ways(amount,coins,n);

        //Memoization->
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // return count_ways(amount,coins,n);

    	// Tabulation+Space-Optimisation
    	vector<int>prv(amount+1),curr(amount+1);
    	prv[0]=curr[0]=1;
        
        for(int c=1;c<=n;++c){
        	for(int amnt=1;amnt<=amount;++amnt){
        		if(coins[c-1]>amnt) curr[amnt]=prv[amnt];
        		else curr[amnt]=prv[amnt]+curr[amnt-coins[c-1]];
        	}
        	prv=curr;
        }	
        return prv[amount];
    }
};