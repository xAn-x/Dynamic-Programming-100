//problem link-->https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-permutations-official/ojquestion

#include <bits/stdc++.h>
using namespace std;

//Tabulation-->Time Complexity->O(n*amount) and Space->O(n*amount)=>

  int coinCombn(int coins[],int n,int amount){
  	//My dp--> 
  	vector<vector<int>>dp(n+1,vector<int>(amount+1,0));	

  	//Meaning ->dp[i][j]=>no of ways to make j amnt using i coins-->	

  	//If amount to pay is 0 then for any no of coin there is 1 way give nothing
  	for(int r=0;r<=n;r++){
  		dp[r][0]=1;
  	}

  	//Filling rest dp->
  	for(int r=1;r<=n;r++){
  		for(int c=1;c<=amount;c++){
  			if(coins[r-1]<=c){
  				dp[r][c]=dp[r][c-coins[r-1]]+dp[r-1][c];
  			}else{
  				dp[r][c]=dp[r-1][c];
  			}
  		}
  	}

  	return dp[n][amount];
}


int coinPermutation(int coins[],int n,int amount){
	
	int no_of_ways=0;

	for(int i = 0; i < n; i++){
		if(i<n-1 and coins[i]==coins[i+1]){
			continue;
		}

		swap(coins[i],coins[0]);

		no_of_ways+=coinCombn(coins,n,amount);

		swap(coins[i],coins[0]);
	}

	return no_of_ways;
} 

void runTime();

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
    
    int n;
    scanf("%d",&n);

    int coins[n];
    for(int i = 0; i < n; i++){
    	scanf("%d", &coins[i]);
    }

    int amount;
    scanf("%d",&amount);

    int no_of_ways=coinPermutation(coins,n,amount);
    printf("no of ways-> %d\n",no_of_ways);
  	
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

