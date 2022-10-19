// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
// Tabulation + Space-Optimisation->
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(),left=k;
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