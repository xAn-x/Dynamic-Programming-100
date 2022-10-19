#link-1 -> https://www.lintcode.com/problem/514/
#link-2 -> https://nados.io/question/paint-fence?zen=true

'''
Note:- Lets Dry run for a testCase and check whar are total no. of ways in which I can pain

if n==0 -> no of ways=0

if n==1 -> no of ways=k (chose any col & paint with it)

if n==2 -> no of ways => no of ways I can paint them with same Col + ways in which can paint in diff col
                      => k*1(what col for 1 same for 2) + k*{k-1}(if i choose a col for 1st can't choose it for 2nd)  
                      => k + k^2 -k
                      => k^2

if n==3 ->ways=> ways if 1st 2 have same col + ways if first 2 have diff
              => {k(first 2 have same col) * {k-1}(as 3 adj pil can't have)} + k*(k-1)(diff cols in first 2) * {k}(as since to have diff we can choose any)
              =>k*{k-1} + k*(k-1)*{k}
              =>(k-1){k+k^2}
              =>(k-1){dp[1]+dp[2]} --->Dp relation  

This is same as fibonacci but a little variation and a good interview Problem
'''

class Solution:
    """
    @param n: non-negative integer, n posts
    @param k: non-negative integer, k colors
    @return: an integer, the total number of ways
    """
    def numWays(self, n, k):
        if(n==1):
            return k
        elif n==2:
            return k*k

        dp=[0 for i in range(n+1)]
        dp[1]=k
        dp[2]=k*k

        for i in range(3,n+1):
            dp[i]=(k-1)*(dp[i-1]+dp[i-2])

        return dp[n]

    # Space-Optimisation
    def numWays(self, n, k):
        if(n==1):
            return k
        elif n==2:
            return k*k

        prv,curr=k,k*k    

        for i in range(3,n+1):
            new=(k-1)*(prv+curr)
            prv=curr
            curr=new

        return curr

