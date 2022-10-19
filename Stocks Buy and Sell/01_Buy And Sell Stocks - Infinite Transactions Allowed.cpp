#include <iostream>
#include <vector>

using namespace std;

//Method-1
int Transaction(vector<int> prices){
    //Buy stock as soon as we encounter uplift and sell it as soon as dipp occured
    int buy_day=0,sell_day=0,no_of_days=prices.size(),profit=0;
    for(int day=1;day<no_of_days;++day){
        //Prices are increasing
        if(prices[day]>=prices[day-1]){
            ++sell_day;
        }else{
            profit+=(prices[sell_day]-prices[buy_day]);
            //Now move buy day and sell day to this point
            buy_day=sell_day=day;
        }
    }
    //Note may happend at end price only increase so consider that profit too
    profit+=(prices[sell_day]-prices[buy_day]);

    return profit;
}


// Method-2=>
int Transaction(vector<int> prices){

/*                                          -----IDEA----- 
  Using Simple Idea of-> if b is a point b/w a & c then dist(a,c)=dist(a,b)+dist(b,c)
  
  So using this idea rather than finding peak-valley -> we will find sum of diffrence of all points on that line
*/

    int n=prices.size(),maxProfit=0;
    for(int i=1;i<n;++i){
        if(prices[i]>prices[i-1]) maxProfit+=(prices[i]-prices[i-1]);
    }
    return maxProfit;
}
  
int  main() {
    int n;
    cin>>n;
    vector<int>prices(n, 0);
    
    for (int i = 0; i < prices.size(); i++) {
      cin >> prices[i];
    }
   
   cout<<Transaction(prices)<<'\n';
   return 0;  
}