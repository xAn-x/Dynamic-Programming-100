# https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1/
class Solution:
	def __tile_floor(self,n,m):
		if(n==1 or n==0):
			return 1
		elif n<0:
			return 0	
		return self.__tile_floor(n-1,m)+self.__tile_floor(n-m,m) #Similar to fibonacci

	def countWays(self, n, m):
	#Recursion->
		# return self.__tile_floor(n,m)

	#Tabulation->
		dp=[0 for i in range(n+1)]
		dp[1]=1

		for i in range(2,n+1):
			if(i<m):
				dp[i]=1
			elif i==m:
				dp[i]=2	
			else:
				dp[i]=dp[i-1]+dp[i-m]

		return dp[n]


