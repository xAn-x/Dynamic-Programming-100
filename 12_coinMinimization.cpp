//problem link-->https://cses.fi/problemset/task/1634#:~:text=CSES%20-%20Minimizing%20Coins&text=Consider%20a%20money%20system%20consisting,number%20of%20coins%20is%20minimal.

#include <bits/stdc++.h>
using namespace std;

void runTime();



/*Method-1=>Recursion-->Time Complexity=>O(n^n)=>

long coinMinimization(int coins[],int n,int target_amount){
	if(target_amount==0){
		return 0;
	}else if(target_amount<0){
		return INT_MAX;
	}

	long minCoinReq=INT_MAX;
	for(int idx=n-1;idx>=0;idx--){
		long coinsReq=INT_MAX;
		if(coins[idx]<=target_amount){
			coinsReq=1+coinMinimization(coins,n,target_amount-coins[idx]);
		}
		minCoinReq=min(coinsReq,minCoinReq);
	}

	return minCoinReq;}

*/


//Method-2=>Tabulation-->Time Complexity=>O(n*target_amount) and Space Complexity=>O(n*target_amount)
long coinMinimization(int coins[],int n,int target_amount){
	long dp[n+1][target_amount+1]={0};

	// Base Case=>
	for(int c=1;c<=target_amount;c++){
		//There is no way to pay any amount if we have no coins=>
		dp[0][c]=INT_MAX;
	}


	// Filling Rest DP->
	for(int c=1;c<=target_amount;c++){
		long  minCoinReq=INT_MAX;
		for(int r=1;r<=n;r++){
			if(coins[r-1]<=c){
				dp[r][c]=min(minCoinReq,1+dp[r][c-coins[r-1]]);
				minCoinReq=dp[r][c];
			}else{
				//If ith coin is >amount then no of coin req=same as if we use only prv i-1 coins
				dp[r][c]=dp[r-1][c];
			}
		}
	}

	return dp[n][target_amount];
}
int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting errors in error.txt
	freopen("error.txt","w",stderr);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    
    int n,target_amount;
    scanf("%d %d",&n,&target_amount);

    int coins[n];
    for(int i = 0; i < n; i++) {
    	scanf("%d",&coins[i]);
  	}


  	long minCoinReq=coinMinimization(coins, n, target_amount);
  	printf("minCoinReq=%ld\n",minCoinReq);
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

