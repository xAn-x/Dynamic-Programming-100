// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/


/*IDEA->
    Let say we have a function 
        func(day,buy,fee)->tell what is max profit i can get if I can buy on day
        func(day,!buy,fee)->tell what is max profit i can get if I can sell on day
    
    if(buy):
        if_buy= -prices[day]+func(day+1,false,fee);
        if_not_buy= 0+func(day+1,true,fee);

        return max(if_buy,if_not_buy)
    else:
        if_sell= (+prices[day]-fee)+func(day+coolDown+1,true,fee);
        if_not_sell= 0+func(day+1,false,fee);
        
        return max(if_sell,if_not_sell)

    Base-Case:
        if day>=n:
            return 0
*/
class Solution {
public:
//  Recursion->
    int maxProfit(vector<int>&prices,int day,int n,bool buy,int fee) {
        if(day>=n)
            return 0;

        if(buy){
            return max(-prices[day]+maxProfit(prices,day+1,n,false,fee),0+maxProfit(prices,day+1,n,true,fee));
        }else{
            return max( (+prices[day]-fee)+maxProfit(prices,day+1,n,true,fee),0+maxProfit(prices,day+1,n,false,fee));
        }
    }

    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        return maxProfit(prices,0,n,true,fee);
    }


//  Memoization->
    int maxProfit(vector<int>&prices,int day,int n,bool buy,int fee,vector<vector<int>>&dp) {
        if(day>=n)
            return 0;

        if(dp[day][buy]!=-1) return dp[day][buy];

        if(buy){
            return dp[day][buy]=max(-prices[day]+maxProfit(prices,day+1,n,0,fee,dp),0+maxProfit(prices,day+1,n,1,fee,dp));
        }else{
            return dp[day][buy]=max( (+prices[day]-fee)+maxProfit(prices,day+1,n,1,fee,dp),0+maxProfit(prices,day+1,n,0,fee,dp));
        }
    }

    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxProfit(prices,0,n,1,fee,dp);
    }


//  Tabulation->
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        dp[n][0]=dp[n][1]=0;

        for(int day=n-1;day>=0;--day){
            //if can buy
            dp[day][1]=max(-prices[day]+dp[day+1][0],0+dp[day+1][1]);
            //if can sell
            dp[day][0]=max(prices[day]-fee+dp[day+1][1],0+dp[day+1][0]);
        }
        
        return dp[0][1];
    }


//  Tabulation + Spce-Optimisation->
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<int>ahead(2,-1),curr(2,-1);

        ahead[0]=ahead[1]=0;

        for(int day=n-1;day>=0;--day){
            //if can buy
            curr[1]=max(-prices[day]+ahead[0],0+ahead[1]);
            //if can sell
            curr[0]=max(prices[day]-fee+ahead[1],0+ahead[0]);

            ahead=curr;
        }
        
        return ahead[1];
    }
};