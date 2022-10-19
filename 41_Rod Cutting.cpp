// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#

//Now here I have choices over cuts and I can make any cut any no of time ->Unbounded knapsack pattern
class Solution{
    // Recursion->O(no_of_peice^n)
    int rodCutting(int price[],int len){
        if(len==0) return 0;
        int max_profit=INT_MIN;
        for(int i=1;i<=len;++i){
            //profit if I make a cut of i-len => price of cut+profit I can get from rem-len i.e len-cut
            max_profit=max(max_profit,price[i-1]+rodCutting(price,len-i));
        }
        return max_profit;
    }

    int rodCutting(int price[],int len,vector<int>&dp){
        if(len==0) return 0;
        if(dp[len]!=-1) return dp[len];

        int max_profit=INT_MIN;
        for(int i=1;i<=len;++i){
            max_profit=max(max_profit,price[i-1]+rodCutting(price,len-i,dp));
        }
        return dp[len]=max_profit;
    }


public:
    int cutRod(int price[], int len) {
        // recursion
        // return rodCutting(price,len);

        vector<int>dp(len+1,-1);

        //memoization->
        // rodCutting(price,len,dp); 

        //Tabulation->
        dp[0]=0;
        for(int l=1;l<=len;++l){
            for(int cut=1;cut<=l;++cut){
                dp[l]=max(dp[l],price[cut-1]+dp[l-cut]);
            }
        }
        return dp[len];
    }
};
