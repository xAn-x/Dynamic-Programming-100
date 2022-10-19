// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*IDEA
    Let say we have a function->
        func(day,buy,left) => that tell max profit I can genrate if I can buy stock on day and can make left more
        func(day,!buy,left) => that tell max profit I can genrate if I can't buy stock on day and can make left more

        Base-Case->
        if day==n:
            return 0

        if(buy):
            if(left==0) return 0;

            if_buy= -prices[day] + func(day+1,false,left-1) 
            if_not_buy= 0 + func(day+1,true,left)
            
            return max(if_buy,if_not_buy)
        else:
            if_sell= prices[day]+func(day+1,true,left) 
            if_sell= 0+func(day+1,false,left) 

            return max(if_sell,if_not_sell)
*/
class Solution {
public:
//  Recursion->
    int maxProfit(vector<int>&prices,int day,int n,bool buy,int left){
        if(day==n) return 0;

        if(buy){
            if(left==0) return 0;
            return max(-prices[day]+maxProfit(prices,day+1,n,false,left-1),0+maxProfit(prices,day+1,n,true,left));
        }else{
            return max(prices[day]+maxProfit(prices,day+1,n,true,left),0+maxProfit(prices,day+1,n,false,left));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),left=2;
        return maxProfit(prices,0,n,true,left);
    }


///  Memoization->
    int maxProfit(vector<int>&prices,int day,int n,int buy,int left,vector<vector<vector<int>>>&dp){
        if(day==n) return 0;
        //if we want to buy but no transection left in that case profit will be zero

        if(dp[day][buy][left]!=-1) return dp[day][buy][left];

        if(buy){
            if(left==0) return dp[day][buy][left]=0;
            return dp[day][buy][left]=max(-prices[day]+maxProfit(prices,day+1,n,0,left-1,dp),0+maxProfit(prices,day+1,n,1,left,dp));
        }else{
            return dp[day][buy][left]=max(prices[day]+maxProfit(prices,day+1,n,1,left,dp),0+maxProfit(prices,day+1,n,0,left,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),left=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(left+1,-1)));
        return maxProfit(prices,0,n,1,left,dp);
    }


//  Tabulation->
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),left=2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(left+1,-1)));

        //if no days left->
        for(int i=0;i<2;++i){
            for(int j=0;j<=left;++j) dp[n][i][j]=0;
        }

        //Filling Dp->
        for(int day=n-1;day>=0;--day){
            for(int lft=0;lft<=left;++lft){
                // if can buy but we have 0 transection left->
                if(lft==0)
                    dp[day][1][lft]=0;
                // if can buy but and have some transection left->
                else
                    dp[day][1][lft]=max(-prices[day]+dp[day+1][0][lft-1],0+dp[day+1][1][lft]);
                
                // if can sell->
                dp[day][0][lft]=max(+prices[day]+dp[day+1][1][lft],0+dp[day+1][0][lft]);
            }
        }
        
        //The ans would be max i can achieve with some or none transection left on buying on 0th day
        int max_profit=0;
        for(int lft=0;lft<=left;++lft){
            max_profit=max(max_profit,dp[0][1][lft]);
        }

        return max_profit;
    }


//  Tabulation + Space-Optimisation->O(n) Time and O(1) Space 
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),left=2;
        vector<vector<int>>ahead(2,vector<int>(left+1,-1)),curr(2,vector<int>(left+1,-1));

        //if no days left->eft
        for(int i=0;i<2;++i){
            for(int j=0;j<=left;++j) ahead[i][j]=0;
        }

        //Filling Dp->
        for(int day=n-1;day>=0;--day){
            for(int lft=0;lft<=left;++lft){
                // if can buy but we have 0 transection left->
                if(lft==0)
                    curr[1][lft]=0;
                // if can buy but and have some transection left->
                else
                    curr[1][lft]=max(-prices[day]+ahead[0][lft-1],0+ahead[1][lft]);
                
                // if can sell->
                curr[0][lft]=max(+prices[day]+ahead[1][lft],0+ahead[0][lft]);
            }
            ahead=curr;
        }

        //The ans would be max i can achieve with some or none transection left on buying on 0th day
        int max_profit=0;
        for(int lft=0;lft<=left;++lft){
            max_profit=max(max_profit,ahead[1][lft]);
        }

        return max_profit;
    }
};