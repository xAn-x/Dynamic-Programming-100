// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*IDEA->
	Let say we have a function 
		func(day,buy,coolDown)->tell what is max profit i can get if I can buy on day
		func(day,!buy,coolDown)->tell what is max profit i can get if I can sell on day
	
	if(buy):
		if_buy= -prices[day]+func(day+1,false);
		if_not_buy= 0+func(day+1,true);

		return max(if_buy,if_not_buy)
	else:
		if_sell= +prices[day]+func(day+coolDown+1,true);
		if_not_sell= 0+func(day+1,false);
		
		return max(if_sell,if_not_sell)

	Base-Case:
		if day>=n:
			return 0
*/
class Solution {
public:
// 	Recursion->
	int maxProfit(vector<int>&prices,int day,int n,bool buy,int coolDown) {
		if(day>=n)
			return 0;

		if(buy){
			return max(-prices[day]+maxProfit(prices,day+1,n,false,coolDown),0+maxProfit(prices,day+1,n,true,coolDown));
		}else{
			return max(+prices[day]+maxProfit(prices,day+coolDown+1,n,true,coolDown),0+maxProfit(prices,day+1,n,false,coolDown));
		}
	}

    int maxProfit(vector<int>& prices) {
    	int n=prices.size(),coolDown=1;
        return maxProfit(prices,0,n,true,coolDown);
    }


// 	Memoization->
	int maxProfit(vector<int>&prices,int day,int n,bool buy,int coolDown,vector<vector<int>>&dp) {
		if(day>=n)
			return 0;

		if(dp[day][buy]!=-1) return dp[day][buy];

		if(buy){
			return dp[day][buy]=max(-prices[day]+maxProfit(prices,day+1,n,0,coolDown,dp),0+maxProfit(prices,day+1,n,1,coolDown,dp));
		}else{
			return dp[day][buy]=max(+prices[day]+maxProfit(prices,day+coolDown+1,n,1,coolDown,dp),0+maxProfit(prices,day+1,n,0,coolDown,dp));
		}
	}

    int maxProfit(vector<int>& prices) {
    	int n=prices.size(),coolDown=1;
    	vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxProfit(prices,0,n,1,coolDown,dp);
    }


// 	Tabulation->
	int maxProfit(vector<int>& prices) {
    	int n=prices.size(),coolDown=1;
    	vector<vector<int>>dp(n+1,vector<int>(2,-1));

    	dp[n][0]=dp[n][1]=0;

    	for(int day=n-1;day>=0;--day){
    		//if can buy
    		dp[day][1]=max(-prices[day]+dp[day+1][0],0+dp[day+1][1]);
    		//if can sell
    		if(day+coolDown+1<n)
                dp[day][0]=max(prices[day]+dp[day+coolDown+1][1],0+dp[day+1][0]);
            else
                dp[day][0]=max(prices[day]+0,dp[day+1][0]);
    	}
        
        
        return dp[0][1];
    }
};