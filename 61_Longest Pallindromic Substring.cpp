#include<bits/stdc++.h>
using namespace std;

class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        
        int max_len=0;
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    max_len=max(max_len,dp[i][j]);
                }
            }
        }
        return max_len;
    }
public:
    int longestPalindromeSubseq(string s) {
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        return longestCommonSubsequence(s,rev_s);      
    }
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.longestPalindromeSubseq(str)<<'\n';
}