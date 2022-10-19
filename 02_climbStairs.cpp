// u can take jumps of 1 , 2 ,3 steps only and need ro return count of possible paths->

#include <bits/stdc++.h>
using namespace std;

/* plain recursion-->
int count_stairPaths(int n) {
	if (n == 0) {
		return 1;
	} else if (n < 0) {
		return 0;
	}

	int count_paths = 0;
	for (int i = 1; i <= 3; i++) {
		count_paths += count_stairPaths(n - i);
	}

	return count_paths;}
*/

//Method 2->Tabulation-->
int count_stairPaths(int n) {
	int dp[n + 1];

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[i] = dp[i - 1];
		} else if (i == 2) {
			dp[i] = dp[i - 1] + dp[i - 2];
		} else {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
	}

	return dp[n];
}
int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	int no_of_paths = count_stairPaths(n);
	printf("No of paths: %d", no_of_paths);

	return 0;
}