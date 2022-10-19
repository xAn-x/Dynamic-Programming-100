//problem link-->https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/min-cost-maze-traversal-official/ojquestion

#include <bits/stdc++.h>
using namespace std;

/*Method 2->Memorization
long long find_cheapest_mazePath(vector<vector<int>>&maze, int rows, int cols , int str_row, int str_col) {
	if (str_row == rows - 1 and str_col == cols - 1) {
		return maze[str_row][str_col];
	} else if (str_row >= rows or str_col >= cols) {
		return INT_MAX;
	}


	long long  if_makeHorizontal_move = find_cheapest_mazePath(maze, rows, cols, str_row, str_col + 1);
	long long if_makeVertical_move = find_cheapest_mazePath(maze, rows, cols, str_row + 1, str_col);

	long long money_spent = maze[str_row][str_col] + min(if_makeVertical_move, if_makeHorizontal_move);

	return money_spent;}
*/

//Method 2->Tabulation-->
long long find_cheapest_mazePath(vector<vector<int>>&maze , int rows , int cols) {

	int dp[rows][cols] = {0};

	dp[rows - 1][cols - 1] = maze[rows - 1][cols - 1];

//Base Case-->
	for (int r = rows - 2; r >= 0; r--) {
		dp[r][cols - 1] = dp[r + 1][cols - 1] + maze[r][cols - 1];
	}

	for (int c = cols - 2; c >= 0; c--) {
		dp[rows - 1][c] = dp[rows - 1][c + 1] + maze[rows - 1][c];
	}


// Filling rest dp
	for (int r = rows - 2; r >= 0; r--) {
		for (int c = cols - 2; c >= 0; c--) {
			dp[r][c] = maze[r][c] + min(dp[r][c + 1], dp[r + 1][c]);
		}
	}

	return dp[0][0];
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

	int row, col;
	scanf("%d %d", &row , &col);


	vector<vector<int>>maze;
	for (int i = 0; i < row; i++) {

		vector<int>array(col);
		for (int j = 0; j < col; j++) {
			scanf("%d", &array[j]) ;
		}

		maze.push_back(array);
	}

	/*Method 1->Plain Recursion
		long long minimumCost = find_cheapest_mazePath(maze, row, col, 0, 0);
	*/
	long long minimumCost = find_cheapest_mazePath(maze, row, col);
	printf("Minimum cost: %lld ", minimumCost);

	return 0;
}
