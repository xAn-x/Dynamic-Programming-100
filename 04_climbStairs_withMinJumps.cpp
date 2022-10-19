//problem link-->

#include <bits/stdc++.h>
using namespace std;

/*Method 1 ->Plain recursion
long long find_min_jumps(int n, int jumps[], int idx = 0) {
	if (idx == n) {
		return 0;
	} else if (idx > n) {
		return INT_MAX;
	}

	long long min_jumps = INT_MAX;
	for (int i = 1; i <= jumps[idx]; i++) {
		long long req_jumps = 1 + find_min_jumps(n, jumps, i + idx);

		min_jumps = min(min_jumps, req_jumps);
	}

	return min_jumps;}
*/

//Method 2->Tabulation
long long find_min_jumps(int n, int jumps[]) {

	int dp[n + 1];

// if I am on n-th block and want to jump to n-th block  ---> 0 jumps
	dp[n] = 0;

	for (int idx = n - 1; idx >= 0; idx--) {
		long long  min_jumps = INT_MAX;
		for (int jump = 1; jump <= jumps[idx] and (jump + idx <= n); jump++) {
			min_jumps = min(min_jumps, 1 + (long long)(dp[idx + jump]));
		}

		dp[idx] = min_jumps;
	}

	return dp[0];
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

	int jumps[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &jumps[i]);
	}

	int min_jumps = find_min_jumps(n, jumps);
	printf("min_jumps: %ld\n", min_jumps);

	return 0;
}