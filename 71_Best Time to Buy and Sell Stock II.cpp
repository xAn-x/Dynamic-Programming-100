// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*IDEA=>
    The Idea is to buy stock when the price drop and wait till stock price reaches its max-value and then sell it
*/

// Method-1=>Complicated to implement->O(n) time and O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),max_profit=0;
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n and prices[j]>=prices[j-1]){
                ++j;
            }

            //When i come out either->price drop or reach end so use (j-1)th day for calculations
            max_profit+=prices[j-1]-prices[i];
            i=j;
        }

        return max_profit;
    }

// Method-2=>Easy to Implement->O(n) time and O(1) space

/*Idea->Comulative sum->
    if we have 3 points a,b,c then c-a == (c-b + b-a)
*/
    int maxProfit(vector<int>& prices) {
        int max_profit=0,n=prices.size();
        for(int i=1;i<n;++i){
            if(prices[i]>prices[i-1]) max_profit+=(prices[i]-prices[i-1]);
        }
        return max_profit;
    }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Recursion and Dynamic Programming ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Solution {
    /*IDEA->
        For each day I have 2 choices buy/sell + if i have bought a stock then can't but any other

        Let we have a->
            func(day,buy) -> will give me max profit I can make till ith day if I can buy here
            func(day,!buy) -> will give me max profit I can make till ith day if I can't but here

        Base-Case
        if day==n:
            return 0

        if buy:
            ->if decided to buy then I have to pay for the stock and i can't buy in future before selling
            if_buy= -prices[day]+func(day+1,!buy)    

            ->if decided to not buy then I don't have to pay for the stock and i can but in future 
            if_not_buy= 0+func(day+1,buy)    

        else:
            ->if decided to sell then I will get prices[day] for the stock and i can buy in future
            if_sell=prices[day]+func(day+1,buy)

            ->if decided not to sell then I will get nothing for the stock and i can't buy in future before selling
            if_sell=func(day+1,!buy)
    */
public:
// Recursion->
    int maxProfit(vector<int>& prices,int day,int n,bool buy){
        if(day==n) return 0;

        if(buy){
            return max(-prices[day]+maxProfit(prices,day+1,n,false) , 0+maxProfit(prices,day+1,n,true));
        }else{
            return max(prices[day]+maxProfit(prices,day+1,n,true) , 0+maxProfit(prices,day+1,n,false));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),day=0;
        bool buy=true;

        return maxProfit(prices,day,n,buy);
    }


// Memoization->
    int maxProfit(vector<int>& prices,int day,int n,int buy,vector<vector<int>>dp){
        if(day==n) return 0;

        if(dp[day][buy]!=-1) return dp[day][buy];
        
        if(buy){
            return dp[day][buy]=max(-prices[day]+maxProfit(prices,day+1,n,0,dp) , 0+maxProfit(prices,day+1,n,1,dp));
        }else{
            return dp[day][buy]=max(prices[day]+maxProfit(prices,day+1,n,1,dp) , 0+maxProfit(prices,day+1,n,0,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),day=0;
        int buy=1;

        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxProfit(prices,day,n,buy,dp);
    }


// Tabulation->
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        // All ele of nth row should be 0
        dp[n][0]=dp[n][1]=0;

        for(int i=n-1;i>=0;--i){
            //if i can buy
            dp[i][1]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
            //if can sell
            dp[i][0]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
        }
        
        // because on day 1 I can only buy not sell
        return dp[0][1];
    }
// Tabulation+Space-Optimisation->
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int>next(2,-1),curr(2,-1);

        // All ele of nth row should be 0
        next[0]=next[1]=0;

        for(int i=n-1;i>=0;--i){
            //if i can buy
            curr[1]=max(-prices[i]+next[0],0+next[1]);
            //if can sell
            curr[0]=max(prices[i]+next[1],0+next[0]);

            next=curr;
        }
        
        // because on day 1 I can only buy not sell
        return next[1];
    }
};

 