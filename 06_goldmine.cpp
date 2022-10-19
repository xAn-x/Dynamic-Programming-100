//problem link-->https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/goldmine-official/ojquestion

#include <bits/stdc++.h>
using namespace std;

/*
6 6

0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

*/

/*Method 1->Plain Recursion-->Time Complexity=>O(n+4^n)

int mineMaxGold(vector<vector<int>>&mine, int rows, int cols, int s_row, int s_col) {

	if (s_row<0 or s_row >= rows or s_col<0 or s_col >= cols)
		return 0;
	if (s_col == cols - 1) {
		return mine[s_row][s_col];
	}

	int maxGoldMine = INT_MIN;

   //Since if I am on 0-th col I can start from any row but for rest need to follow the order-->
	if (s_col == 0) {
		for (int r = 0; r < rows; r++) {
			int if_move_hori = mineMaxGold(mine, rows, cols, r, s_col + 1);
			int if_move_upperDiag = mineMaxGold(mine, rows, cols, r - 1, s_col + 1);
			int if_move_lowerDiag = mineMaxGold(mine, rows, cols, r + 1, s_col + 1);

			int goldMine = mine[r][s_col] + max(if_move_hori, max(if_move_upperDiag, if_move_lowerDiag));
			maxGoldMine = max(maxGoldMine, goldMine);
		}
	} else {

		int if_move_hori = mineMaxGold(mine, rows, cols, s_row, s_col + 1);
		int if_move_upperDiag = mineMaxGold(mine, rows, cols, s_row - 1, s_col + 1);
		int if_move_lowerDiag = mineMaxGold(mine, rows, cols, s_row + 1, s_col + 1);

		int goldMine = mine[s_row][s_col] + max(if_move_hori, max(if_move_upperDiag, if_move_lowerDiag));
		maxGoldMine = max(maxGoldMine, goldMine);
	}



	return maxGoldMine;}

*/

//Method 2->Tabulation
int mineMaxGold(vector<vector<int>> &mine, int rows, int cols) {
	int dp[rows][cols];

	fill(dp[0], dp[0] + rows * cols, -1);

	//Meaning-->at dp[i][j] it store max gold I can mine till last col
	for (int r = 0; r < rows; r++)
		dp[r][cols - 1] = mine[r][cols - 1];

	for (int c = cols - 2; c >= 0; c--) {
		for (int r = rows - 1 ; r >= 0; r--) {
			int if_make_hori = dp[r][c + 1];
			int if_make_upper = (r != 0) ? dp[r - 1][c + 1] : INT_MIN;
			int if_make_lower = (r != rows - 1) ? dp[r + 1][c + 1] : INT_MIN;

			dp[r][c] = mine[r][c] + max(if_make_hori, max(if_make_upper, if_make_lower));
		}
	}


	int maxGold = dp[0][0];
	for (int r = 1; r < rows; r++) {
		maxGold = max(maxGold, dp[r][0]);
	}

	return maxGold;
}

int main() {

//add the two lines below for fast i/o
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int row, col;
	scanf("%d %d", &row , &col);


	vector<vector<int>>mine(row);
	for (int i = 0; i < row; i++) {

		vector<int>array(col);
		for (int j = 0; j < col; j++) {
			scanf("%d", &array[j]) ;
		}

		mine[i] = array;
	}

	// for (int i = 0; i < row; i++) {
	// 	for (int j = 0; j < col; j++) {
	// 		cout << mine[i][j] << " ";
	// 	} cout << '\n';
	// }
	// cout << '\n';

	/*Plain recursion
		int maxGold = mineMaxGold(mine, row, col, 0, 0);
	*/

	int maxGold = mineMaxGold(mine, row, col);
	printf("maxGold: %d\n", maxGold);;
	return 0;
}