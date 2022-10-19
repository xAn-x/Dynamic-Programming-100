// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution {
public:
/*Method-1=>O(n^2)
For each day find what is the day on future u can sell stock to gain max profit
*/
    int maxProfit(vector<int>& prices) {
        int days=prices.size(),max_profit=0;
        for(int i=0;i<days;++i){
            for(int j=i+1;j<days;++j){
                max_profit=max(prices[j]-prices[i],max_profit);
            }
        }
        return max_profit;
    }

/*Method-2=>O(n) time and space
Create an array that takes count of what is the max-price a stock can achive in future
        => arr[i]->after ith-day what is the max price of stock

        Eg:prices = [7,1,5,3,6,4]
            arr  = [7,6,6,6,6,4]

        Now using this array we can get max profit
*/
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>arr(n);
        int future_max=INT_MIN;
        for(int i=n-1;i>=0;i--){
            future_max=max(future_max,prices[i]);
            arr[i]=future_max;
        }

        int max_profit=0;
        for(int i=0;i<n;++i){
            max_profit=max(arr[i]-prices[i],max_profit);
        }

        return max_profit;
    }

/*Method-3=>O(n) time and O(1) space
    We will approch the problem similar to Method-2 but this time rather than taking acount what is max profit I can get in future if I decide to buy here I will simply find what max profit I can make if I decide to sell on ith day

    -->and to get that we just need the min_price we have encounter till now as that transection will give us max profit
*/

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),min_price=prices[0],max_profit=0;
        for(int i=1;i<n;++i){
            min_price=min(min_price,prices[i]);
            max_profit=max(prices[i]-min_price,max_profit);
        }
        return max_profit;
    }

};