//problem link-->

/*Ques->
	You need to find no of ways of making a sum S by rolling a dice one or more time

	Eg:- sum=3 --> 1 1 1 , 1 2 , 2 1 , 3 ==>No of ways =4
*/

#include <bits/stdc++.h>
using namespace std;

/*Method 1->Plain Recursion->Time Complexity=>O(6^sum)

long long no_of_ways(int sum) {

	if (sum == 0) {
		return 1;//don't do anything
	} else if (sum < 0) {
		return 0;
	}

	long long ways = 0;
	for (int i = 1; i <= 6; i++) {
		ways += no_of_ways(sum - i);
	}

	return ways;}

*/


//Method 2->Tabulation->Time Complexity=>O(sum)

long long no_of_ways(int sum) {
	int dp[sum + 1] = {0};

	//Base Case --> if sum == 0 --> return 1
	dp[0] = 1;

	// Meaning->dp[i]==>no of ways to create sum i using dice-->
	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= 6 and i - j >= 0 ; j++) {
			dp[i] += dp[i - j];
		}
	}

	return dp[sum];
}

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int sum;
	scanf("%d", &sum);

	long long ways = no_of_ways(sum);
	printf("no of ways: %d\n", ways);
	return 0;
}
