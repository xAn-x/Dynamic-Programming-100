class Solution{
// Method1()- recursive solution(Top- down approach)
	// time complexity - O(3^(m+n))
	// space complexity - O(m+n)
	public static int LCSubStrM1(char[] X, char[] Y, int m, int n, int lcsCount) {
		if (m <= 0 || n <= 0)
			return lcsCount;
		
		int lcsCount1=lcsCount;
		if (X[m - 1] == Y[n - 1])
			lcsCount1 = LCSubStrM1(X, Y, m - 1, n - 1, lcsCount + 1);

		int lcsCount2 = LCSubStrM1(X, Y, m, n - 1, 0);
		int lcsCount3 = LCSubStrM1(X, Y, m - 1, n, 0);

		return Math.max(lcsCount1, Math.max(lcsCount2, lcsCount3));
	}

	
	// Method2A1()- recursive solution with memoization (Top-down approach caching on method level)
	public static int LCSubStrM2A1(char[] X, char[] Y, int m, int n, int lcsCount, Integer[][][] dp) {
		if (m <= 0 || n <= 0)
			return lcsCount;

		if (dp[m][n][lcsCount] != null)
			return dp[m][n][lcsCount];

		int lcsCount1=lcsCount;
		if (X[m - 1] == Y[n - 1])
			lcsCount1 = LCSubStrM2A1(X, Y, m - 1, n - 1, lcsCount + 1, dp);

		int lcsCount2 = LCSubStrM2A1(X, Y, m, n - 1, 0, dp);
		int lcsCount3 = LCSubStrM2A1(X, Y, m - 1, n, 0, dp);

		return dp[m][n][lcsCount] = Math.max(lcsCount1, Math.max(lcsCount2, lcsCount3));
	}

	// Method2A2()- recursive solution with memoization (Top-down approach caching on global level)
	public static int LCSubStrM2A2(char[] X, char[] Y, int m, int n, int lcsCount) {
		if (m <= 0 || n <= 0)
			return lcsCount;

		if (dp[m][n][lcsCount] != null)
			return dp[m][n][lcsCount];

		int lcsCount1=lcsCount;
		if (X[m - 1] == Y[n - 1])
			lcsCount1 = LCSubStrM2A2(X, Y, m - 1, n - 1, lcsCount + 1);

		int lcsCount2 = LCSubStrM2A2(X, Y, m, n - 1, 0);
		int lcsCount3 = LCSubStrM2A2(X, Y, m - 1, n, 0);

		return dp[m][n][lcsCount] = Math.max(lcsCount1, Math.max(lcsCount2, lcsCount3));
	}

	// Method3()- DP solution(Bottom up approach)
	// time complexity - O(m*n)
	// space complexity - O(m*n)
	public static int LCSubStrA3(char[] X, char[] Y, int m, int n) {
		int memo[][] = new int[m + 1][n + 1];
		int result = 0;

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j == 0) {
					memo[i][j] = 0;
				} else if (X[i - 1] == Y[j - 1]) {
					memo[i][j] = memo[i - 1][j - 1] + 1;
					result = Math.max(result, memo[i][j]);
				} else {
					memo[i][j] = 0;
				}
			}
		}
		return result;
	}

	public:
    public int findLength(char[] nums1, char[] nums2) {
        return LCSubStrA3(nums1,nums2,nums1.length,nums2.length);
    }
}