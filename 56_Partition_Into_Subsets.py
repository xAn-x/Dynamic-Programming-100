# https://nados.io/question/partition-into-subsets?zen=true

'''
IDEA:-
No of ways to divide n people in kteams is
    ways=No of ways in which n-1 people can for k teams + No of ways in which n-1 people can k-1 team
    In 1st case->nth person will choose in which team he need to be sit
    In second case ->nth person will start it's new team so to make total of k teams

    ways = No of ways in which n-1 people can for k teams*k + No of ways in which n-1 people can k-1 team*1
'''

class Solution:
#Recursion->
    def __partition(self,n,k):
        if(n==0 or k>n):
            return 0
        if(n==k):
            return 1

        return self.__partition(n-1,k)*k + self.__partition(n-1,k-1)  


#Memoization->
    def __partition(self,n,k,dp):
        if(n==0 or k>n):
            return 0
        if(n==k):
            return 1

        if dp[n][k]!=-1:
            return dp[n][k]

        dp[n][k]=(self.__partition(n-1,k,dp)*k + self.__partition(n-1,k-1,dp))
        return dp[n][k]



    def Partition_into_subsets(self,n , k):
    # Recursive->
        # return self.__partition(n,k)

    #Memoization->
        # dp = [[-1 for i in range(20)] for j in range(20)]
        # return self.__partition(n,k,dp)

    #Tabulation->
        Table to store results of subproblems
        dp = [[0 for i in range(k + 1)] for j in range(n+1)]

        # Base cases
        for i in range(n + 1):
            dp[i][0] = 0
     
        for i in range(k + 1):
            dp[0][k] = 0

        # Fill rest of the entries in dp[][] in bottom up manner
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                if (j == 1 or i == j):
                    dp[i][j] = 1
                else:
                    dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1]
        
        return dp[n][k]

n = int(input())
k = int(input())

obj=Solution()
print(obj.Partition_into_subsets(n , k))