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


int count_targetSum_subset(vi &nums, int n, int targetSum) {
	//Same as find_target but here need to find no of time we can->

	vector<vi>dp(n + 1, vi(targetSum + 1));

	// loop(c,1,targetSum,1) dp[0][c]=0-->by default 0 hai

	loop(r, 0, n, 1) dp[r][0] = 1;

	loop(r, 1, n, 1) {
		loop(c, 1, targetSum, 1) {
			if (nums[r - 1] > c) dp[r][c] = dp[r - 1][c];
			else dp[r][c] = dp[r - 1][c] + dp[r - 1][c - nums[r - 1]];
		}
	}

	return dp[n][targetSum];
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
	freopen("error.txt", "w", stderr);
	//For getting output in output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vi nums(n);
	loop(i, 0, n - 1, 1) cin >> nums[i];

	int target; cin >> target;

	int count = count_targetSum_subset(nums, n, target);
	cout << count << '\n';
	runTime();

	return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
