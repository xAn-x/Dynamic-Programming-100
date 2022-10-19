#link-1 -> https://www.lintcode.com/problem/514/
#link-2 -> https://nados.io/question/paint-fence?zen=true


class Solution:
    """
    @param n: non-negative integer, n posts
    @param k: non-negative integer, k colors
    @return: an integer, the total number of ways
    """

#Method-1 =>Find all subseq and count those which are valid ->O(2^n)


#Method-2 Plain Recursion
    def __helper(self,n,k,lst_col,count):
        if n==0 :
            return 1
        
        totWays=0
        for col in range(k):
            if col==lst_col:
                # We can only col if less than 2 adj-cols are painted with this col 
                if count<2: 
                    totWays+=self.__helper(n-1,k,col,count+1)
            else:
                totWays+=self.__helper(n-1,k,col,1)

        return  totWays    



#Method-3-> Memoization
    def __helper(self,n,k,lst_col,count,dp):
        if n==0 :
            return 1
        
        if dp[n][lst_col][count]!=-1:
                return dp[n][lst_col][count]

        totWays=0
        for col in range(k):
            if col==lst_col:
                # We can only col if less than 2 adj-cols are painted with this col 
                if count<2: 
                    totWays+=self.__helper(n-1,k,col,count+1,dp)
            else:
                totWays+=self.__helper(n-1,k,col,1,dp)

        dp[n][lst_col][count]=totWays      
        return totWays     



    def numWays(self, n, k):
        count,lst_col=0,-1 #count represent no of consecutive fences with same colors
        # return self.__helper(n,k,lst_col,count) # Recursion

        dp = [ [[-1 for j in range(3)] for col in range(k+1)] for i in range(n+1)]
        # print(dp) 
        return self.__helper(n,k,lst_col,count,dp) #Memoization
        
