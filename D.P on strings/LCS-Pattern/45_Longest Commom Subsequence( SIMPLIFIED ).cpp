// https://leetcode.com/problems/longest-common-subsequence/

/*                                          -----IDEA----
    Let say we have 2 string 
        Now all possible ways are->
            # if lst char of both string matches then this would definately in lcs so ans=1+lcs of rest-str1 and rest-str2
            # if lst char of both string don't matches then we have 2 choices
                    # Skip the last char of str1 as there are chances such that str2 will share something with rest str2
                    # Skip the last char of str2 as there are chances such that str1 will share something with rest str1
*/

class Solution {
    int lcs(string&txt1,int l1,string&txt2,int l2){
        if(l1==0 or l2==0) return 0;

        if(txt1[l1-1]==txt2[l2-1]) return 1+lcs(txt1,l1-1,txt2,l2-1);
        else return max(lcs(txt1,l1-1,txt2,l2),lcs(txt1,l1,txt2,l2-1));
    }
    //Memoization->
    int lcs(string&txt1,int l1,string&txt2,int l2,vector<vector<int>>&dp){
        if(l1==0 or l2==0) return 0;

        if(dp[l1][l2]!=-1) return dp[l1][l2];

        if(txt1[l1-1]==txt2[l2-1]) return 1+lcs(txt1,l1-1,txt2,l2-1,dp);
        else return max(lcs(txt1,l1-1,txt2,l2,dp),lcs(txt1,l1,txt2,l2-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();

         //Plain recursion->
        // return lcs(text1,l1,text2,l2); 
        
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));

        //Memoization->
        // return lcs(text1,l1,text2,l2,dp);

        //Tabulation->
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[l1][l2];
    }
};