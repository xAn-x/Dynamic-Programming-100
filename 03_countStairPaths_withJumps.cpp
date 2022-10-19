//U are on 0th stair u need to go to nth and for that u have n value where ith value denote how far u can jump from ith stair u need to find no of possible paths-->

#include <bits/stdc++.h>
using namespace std;

/*Method 1->Plain Recursion
int count_StairPaths_withJumps(int n, int arr [], int idx) {
	if (idx == n) {
		return 1;
	} else if (idx > n) {
		return 0;
	}

	int count_paths = 0;
	for (int i = 1; i <= arr[idx]; i++) {
		count_paths += count_StairPaths_withJumps(n, arr, i + idx);
	}

	return count_paths;}
*/

//Method 2_>Tabulation->
int count_StairPaths_withJumps(int n, int arr[]) {
	int dp[n + 1] = {0};

	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= arr[i] and j + i <= n; j++) {
			dp[i] += dp[i + j];
		}
	}

	return dp[0];
}

int main() {

// //add the two lines below for fast i/o
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int no_of_paths = count_StairPaths_withJumps(n, arr);
	printf("no_of_paths: %d", no_of_paths);

	return 0;
}