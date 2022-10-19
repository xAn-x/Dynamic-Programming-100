// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

	/*							----IDEA----
		Idea is ->Since we can can buy only 1stack at a time  we will use that stack untill we get some stack such that new buy state is better than old i.e if profit-new stock price>old stock price ....

		Now same with selling we can only sell those stocks that we had bought sometime and will only sell if new sell profit is better than prv. 
	*/ 

class Solution {
    public int maxProfit(int[] prices, int fee) {
        int buy_state_val = -prices[0];
        int sell_state_profit = 0;
        
        for (int i = 1; i < prices.length; i++) {
          int new_sell_state_profit = 0;
          int new_buy_state_val = 0;

          if (sell_state_profit - prices[i] > buy_state_val) {
            new_buy_state_val = sell_state_profit - prices[i];
          } else {
            new_buy_state_val = buy_state_val;
          }

          if (buy_state_val + prices[i] - fee > sell_state_profit) {
            new_sell_state_profit = buy_state_val + prices[i] - fee;
          } else {
            new_sell_state_profit = sell_state_profit;
          }

          buy_state_val = new_buy_state_val;
          sell_state_profit = new_sell_state_profit;
        }

        return sell_state_profit;
    }
}