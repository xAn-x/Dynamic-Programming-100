//problem link-->https://www.geeksforgeeks.org/maximum-profit-sale-wines/


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

/*Method-1=>Time-complexity=>O(2^n)
int maxProfitExtracter(vector<int>& wine_prices, int st , int end, int yr) {
	//Since current bottle choice can disturb the future choices->Use Dp

	//At every Move try picking from one end and find which choise will give max profit-
	if (st == end) return yr * wine_prices[st];

	if (st > end) {
		return 0;
	}


	//If decide to choose bottle at start->
	int profit_withSt = (yr * wine_prices[st] ) + maxProfitExtracter(wine_prices, st + 1, end, yr + 1);

	int profit_withEnd = (yr * wine_prices[end]) + maxProfitExtracter(wine_prices, st, end - 1, yr + 1);


	return max(profit_withSt, profit_withEnd);}
*/

// Method-2=>Tabulation->
int maxProfitExtracter(vector<int>& wine_prices, int st , int end , int yr) {
	int n = wine_prices.size();

	vector<vi>dp(n, vi(n));

	//Filling Dp->


	return 0;
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

	vector<int>wine_prices(n);

	loop(i, 0, n - 1, 1) cin >> wine_prices[i];

	int maxProfit = maxProfitExtracter(wine_prices, 0, n - 1, 1);
	cout << maxProfit << endl;

	runTime();

	return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
