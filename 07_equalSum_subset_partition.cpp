//problem -->Can Have 2 subset with equal sum-->

#include <bits/stdc++.h>
using namespace std;

//problem link-->


//HEADER FILES---------------------------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <math.h>
#include <string>

using namespace std;

//MACROS---------------------------------------------------------------------------------------------------------------

#define INF INT_MAX
#define neg_INF INT_MIN

#define loop(i,st,end,jump) for(auto i = st; i<=end; i+=jump)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;


typedef long long ll;
#define mod 1e9+7;

void runTime();

//---------------------------------------------------------------------------------------------------------------------

bool can_have_equalSumSubset(vi &nums, int n) {
	/*
		Since 2 the SubSet should contain all elements=>sum of both subset=totalSum/2

		Now for that totalSum of subset should be even as odd num can't be divided into 2 parts

		Now problem boil down to find finding subsubet with sum totalSum/2 as if I find one then the remaining ele will form other half;*/

	//If no of ele is zero then only one subset is possible i.e empty subset->
	if (n == 0) return false;

	//Calc totalSum
	int totalSum = 0;
	loop(i, 0, n - 1, 1) totalSum += nums[i];

	if ((totalSum % 2) != 0) return false;

	int halfSum = totalSum / 2;

	vector<vector<bool>>dp(n + 1, vector<bool>(halfSum + 1));

	//Meaning of dp[i][j]->can i have sum j using first i ele

	//Base case->

	//If no of ele is 0->
	loop(r, 1, halfSum, 1) dp[0][r] = false;

	//If sum is 0->
	loop(c, 0, n, 1) dp[c][0] = true;


	//Filling rest dp->

	loop(r, 1, n, 1) {
		loop(c, 1, halfSum, 1) {
			if (nums[r - 1] > c) dp[r][c] = dp[r - 1][c];
			else dp[r][c] = (dp[r - 1][c] || dp[r - 1][c - nums[r - 1]]);
		}
	}

	return dp[n][halfSum];
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

	int n;
	cin >> n;

	vector<int>vec(n);
	loop(i, 0, n - 1, 1) cin >> vec[i];

	bool can_divide = can_have_equalSumSubset(vec, n);
	cout << boolalpha << can_divide << "\n";
	return 0;
}
