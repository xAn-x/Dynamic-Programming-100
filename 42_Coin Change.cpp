// https://leetcode.com/problems/coin-change/
class Solution {
	int coinChange(vector<int>&coins,int n,int amount){
		if(amount==0) return 0;
        //I don't have any coin then to can't pay any amnt  or if amount is -ve then also can't pay for that 
		if(amount<0 or n==0) return 1e9;

		//if i decide not to use some coin i will skip but if i decide to chose it then I can still use it in next turn also so don't skip for now
		return min(coinChange(coins,n-1,amount),1+coinChange(coins,n,amount-coins[n-1])); 
	}

	int coinChange(vector<int>&coins,int n,int amount,vector<vector<int>>&dp){
		if(amount==0) return 0;
        //I don't have any coin then to can't pay any amnt  or if amount is -ve then also can't pay for that 
		if(amount<0 or n==0) return 1e9;

		if(dp[n][amount]!=-1) return dp[n][amount];
		//if i decide not to use some coin i will skip but if i decide to chose it then I can still use it in next turn also so don't skip for now
		return dp[n][amount]=min(coinChange(coins,n-1,amount,dp),1+coinChange(coins,n,amount-coins[n-1],dp)); 
	}
	
public:
    int coinChange(vector<int>& coins, int amount) {
    	int n=coins.size();

        //recursion->
        // int ans= coinChange(coins,n,amount);


        //Memoization->
        // vector<vector<int>>dp(n+1,amount+1);
        // int ans coinChange(coins,n,amount,dp);

        // Tabulation+Space-Optimisation
    	vector<int>prv(amount+1,1e9),curr(amount+1,1e9);
    	prv[0]=curr[0]=0;
        
        for(int c=1;c<=n;++c){
        	for(int amnt=1;amnt<=amount;++amnt){
        		if(coins[c-1]>amnt) curr[amnt]=prv[amnt];
        		else curr[amnt]=min(prv[amnt],1+curr[amnt-coins[c-1]]);
        	}
        	prv=curr;
        }	
        int ans=prv[amount];
        return (ans>=1e9)?-1:ans;
    }
};