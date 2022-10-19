//problem link-->

#include <bits/stdc++.h>
using namespace std;


/* Method 1-->Plain recursion=>
int find_maxProfit(int n, vector<int> & weights, vector<int> & values, int capacity, int idx) {
	//if we process all elements or our bag is full we can't take any more
	if (capacity <= 0 or idx == n) {
		return 0;
	}//if weights[idx]>capacity then we can't take it
	else if (weights.at(idx) > capacity) {
		return find_maxProfit(n, weights, values, capacity, idx + 1);
	}

	int if_inc_item = values.at(idx) + find_maxProfit(n, weights, values, capacity - weights.at(idx), idx + 1);
	int if_not_inc_item = find_maxProfit(n, weights, values, capacity, idx + 1);

	return max(if_inc_item, if_not_inc_item);}
*/

/*Method 2-Memorization=>
int find_maxProfit(int n, vector<int> & weights, vector<int> & values, int capacity, int idx, vector<vector<int> > & dp) {
	//if we process all elements or our bag is full we can't take any more
	if (capacity <= 0 or idx == n) {
		return 0;
	}//if weights[idx]>capacity then we can't take it
	else if (weights.at(idx) > capacity) {
		return dp[idx][capacity] = find_maxProfit(n, weights, values, capacity, idx + 1, dp);
	}

	if (dp[idx][capacity] > 0) {
		return dp[idx][capacity];
	}

	int if_inc_item = values.at(idx) + find_maxProfit(n, weights, values, capacity - weights.at(idx), idx + 1, dp);
	int if_not_inc_item = find_maxProfit(n, weights, values, capacity, idx + 1, dp);

	return dp[idx][capacity] = max(if_inc_item, if_not_inc_item);}
*/

//Method 3->Tabulation->
/*
int find_maxProfit(int n, vector<int> & weights, vector<int> & values, int capacity) {

	vector< vector<int> >dp;

	for (int idx = 0; idx <= n; idx++) {
		vector<int>arr(capacity + 1);

		dp.push_back(arr);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {
			if (weights[i] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(dp[i - 1][j], values[i] + dp[i - 1][j - weights[i]]);
			}
		}
	}

	return dp[n][capacity];
}
*/

//Method 4->Tabulation + space-Optimisation->O(cap) space
int find_maxProfit(int n, ve1tor<int> & weights, vector<int> & values, int capacity) {

	vector<int>prv(capacity+1),curr(capacity+1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {
			if (weights[i] > j) {
				curr[j] = prv[j];
			} else {
				curr[j] = max(prv[j], values[i] + prv[j - weights[i]]);
			}
		}
		prv=curr;
	}

	return prv[capacity];
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

	vector<int> weights(n);
	vector<int> values(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &weights[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &values[i]);
	}

	int capacity;
	scanf("%d", &capacity);

	/* Plain recursion->
		int max_profit = find_maxProfit(n, weights, values, capacity, 0, dp);
	*/

	/*Method 2->Memorization
	vector < vector<int> >dp;

	for (int i = 0; i <= n; i++) {
		vector<int>arr(capacity + 1);
		dp.push_back(arr);}
	int max_profit = find_maxProfit(n, weights, values, capacity, 0, dp);
	*/

	//Method 3->Tabulation
	int max_profit = find_maxProfit(n, weights, values, capacity);

	printf("max_profit = %d", max_profit);
	return 0;
}