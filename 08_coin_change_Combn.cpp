//problem link-->https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-combination-official/ojquestion

#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Recursion --> Time Complexity->O(2^n) and Space->O(n)->

int coinCombn(int coins[],int n,int amount){
	if(amount==0) return 1;

	if(n<=0) return 0;

	//No of ways if n-1 th coin is greater than amount-->
	if(coins[n-1]>amount) return coinCombn(coins,n-1,amount);

	//No of ways if n-1 th coin is smaller than amount-->
	else return coinCombn(coins,n,amount-coins[n-1])+coinCombn(coins,n-1,amount);
}

*/


/*Tabulation-->Time Complexity->O(n*amount) and Space->O(n*amount)=>

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

  	// Traversing last col to get no of ways to form amnt using n coins-->

  	for(int r=0;r<=n;r++){
  		for(int c=0;c<=amount;c++){
  			printf("%d ",dp[r][c]);
  		}printf("\n");
  	}

  	return dp[n][amount];
  }

*/

//Method 3->Tabulation 2-->
int coinCombn(int coins[], int n, int amount) {
	int dp[amount + 1] = {0};

	dp[0] = 1;

	for (int j = 1; j <= amount; j++) {
		for (int i = 0; i < n; i++) {
			if (coins[i] <= j) {
				dp[j] += dp[j - coins[i]];
			}
		}
	}

	return dp[amount];
}

int main() {

// add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting errors in error.txt
	freopen("error.txt", "w", stderr);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	int coins[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &coins[i]);

	int amnt;
	scanf("%d", &amnt);

	int noOfWays = coinCombn(coins, n, amnt);
	printf("no of ways-> %d\n", noOfWays);

	runTime();

	return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}

