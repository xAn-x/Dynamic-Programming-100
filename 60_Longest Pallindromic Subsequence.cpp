// https://leetcode.com/problems/longest-palindromic-subsequence/

// Method-1=>Find all subseq -> get the length of longest pallindromic->O(expon)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*Method-2=>Using Recursion
    I will create a func lps(s,st,end) -> return length of lps b/w st and end

        if s[st]==s[end]:
            return 2+lps(s,st+1,end-1)
        else:
            return max(lps(s,st+1,end),lps(s,st,end-1))
        
        Base-Case->
        if(st==end):
            if string only have one char then it will surely be pallindromic
            return 1
        else if(st>end):
            if string is empty => len(lps)==0
            return 0
*/
class Solution {
public:
// Recursion->
    int lps(string&s,int st,int end){
        if(st==end)
            return 1;
        else if(st>end)
            return 0;

         if (s[st]==s[end])
            return 2+lps(s,st+1,end-1);
        else
            return max(lps(s,st+1,end),lps(s,st,end-1));
    }

    int longestPalindromeSubseq(string s) {
        return lps(s,0,s.size()-1);
    }


// Memoization->
    int lps(string&s,int st,int end,vector<vector<int>>&dp){
        if(st==end)
            return 1;
        else if(st>end)
            return 0;

        if(dp[st][end]) return dp[st][end];

        if (s[st]==s[end])
            return dp[st][end]=2+lps(s,st+1,end-1,dp);
        else
            return dp[st][end]=max(lps(s,st+1,end,dp),lps(s,st,end-1,dp));
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        return lps(s,0,n-1,dp);
    }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Method-3=>Using LCS to get LPS-->
/*
    IDEA-> if I find lcs(s,s.reverse())-->
    The the length of LCS would be length of LPS
    
    refrence->https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=29
*/
class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();
        vector<int>prv(l2+1,0),curr(l2+1,0);
        
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prv[j-1];
                }else{
                    curr[j]=max(curr[j-1],prv[j]);
                }
            }
            prv=curr;
        }

        return prv[l2];
    }
public:
    int longestPalindromeSubseq(string s) {
        string rev_s=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,rev_s);      
    }
};