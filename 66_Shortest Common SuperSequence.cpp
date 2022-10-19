// https://leetcode.com/problems/shortest-common-supersequence/
// refrence->https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32
/*NOTE->
    I can always have a string that will be superSequence for 2 strings s1 and s2
    that super sequence whould be--> s1+s2
    Eg: s1="abac" s2="cab"  -> superSequence->"abaccab"


    If I take out the lcs of s1 and s2 and then try to match rest car then i am good to go-->
    s1="abac" s2="cab"
    lcs=>ab   
        -> to make s2 -> 'c'+lcs 
        -> to make s1 -> lcs+'ac'

    Eg-2:
    s1="adbc"  s2="dac"
    lcs=>dc
    
    s1->a+d+b+c
    s2->d+a+c

    super sequence->adabc
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.size(),l2=str2.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1));

        // Making lcs dp-grid
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        int len=dp[l1][l2],r=l1,c=l2;
        string superSeq;
        while(r>0 and c>0){
            if(str1[r-1]==str2[c-1]){
                // This is common so will take only once
                superSeq.push_back(str1[r-1]);
                r--;c--;
            }else if(dp[r-1][c]>dp[r][c-1]){
                // so str2[c-1] is not +nt in lcs take it and move to dircn of lcs
                superSeq.push_back(str1[r-1]);
                r--;
            }else{
                // so str1[r-1] is not +nt in lcs take it and move to dircn of lcs
                superSeq.push_back(str2[c-1]);
                c--;
            }
        }
        
        while(c>0){
            superSeq.push_back(str2[c-1]);
            --c;
        }
        
        while(r>0){
            superSeq.push_back(str1[r-1]);
            --r;
        }
        
        //Here the string we will get will be reverse of needed as we started from back ->
        reverse(superSeq.begin(),superSeq.end());
        return superSeq;
    }
};