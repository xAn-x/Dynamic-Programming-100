#include <iostream>
#include <vector>

using namespace std;

// Finding next greater->O(n) Time and Space

/*
int Transaction(vector<int>& arr){
  //Find Max Price stock can achieve on days ahead for every day and then corres to that find max-profit 

  int n=arr.size();
  vector<int>max_in_rt(n);
  max_in_rt[n-1]=-1;

  int maxEle=arr[n-1];
  for(int i=n-2;i>=0;--i){
      if(arr[i]>maxEle){
          max_in_rt[i]=-1;
          maxEle=arr[i];
      }else{
        max_in_rt[i]=maxEle;
      }
  }

  //Traverse and find what is maxProfit u can get->
  int maxProfit=-1e9;
  for(int i=0;i<n-1;++i){
      maxProfit=max(maxProfit,max_in_rt[i]-arr[i]);
  }
  return maxProfit;
}
*/


// O(1)->Space
int Transaction(vector<int>& prices){
  // Rather than find max-inflation on right find min inflation at left and then for every day try to sell that stock to achive max-profit
    int minPrice=prices[0],maxProfit=-1,n=prices.size();
    for(int d=1;d<n;++d){
        if(prices[d]<minPrice){
          minPrice=prices[d];
        }

        maxProfit=max(maxProfit,prices[d]-minPrice);
    } 
    return maxProfit;
}
    
int  main() {
    int n;
    cin>>n;
    vector<int>arr(n, 0);
    
    for (int i = 0; i < arr.size(); i++) {
      cin >> arr[i];
    }
   
   cout<<Transaction(arr)<<'\n';
   return 0;  
}