// https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	// <-------Recursion------->
	int maxCutProd_rec(int n){
		if(n==2) return n;

		int maxProd=0;
		for(int i=1;i<=n;++i){
			maxProd=max(maxProd,i*maxCutProd_rec(n-i));
		}

		return maxProd;
	}


	// <-------Memoization------->
	int memoHelper(int n,vector<int>&dp){
		if(n==2) return n;
		
		if(dp[n]!=-1) return dp[n];

		int maxProd=0;
		for(int i=1;i<=n;++i){
			maxProd=max(maxProd,i*memoHelper(n-i,dp));
		}

		return dp[n]=maxProd;
	}

	int maxCutProd_memo(int n){
		vector<int>dp(n+1,-1);
		return memoHelper(n,dp);
	}
}; 


int main(){
 //add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;

	Solution obj;
	// cout<<obj.maxCutProd_rec(n)<<"\n";      	
	// cout<<obj.maxCutProd_memo(n)<<"\n";      	
	cout<<obj.maxCutProd_tabulation(n)<<"\n";      	

	return 0;
}