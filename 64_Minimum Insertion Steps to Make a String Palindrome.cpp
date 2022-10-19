// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

/*
 if We hace a string str then it can always be converted to a pallindrome just by insertion->
    just append the reverse string in the end

    for eg-> absd ---> absddsba
    
 
 Now,We want min no of operation to make our string pallindrome->

 Idea-> We will let the pallindromic part of our string intact and then find how many char we need to insert in order to make the string pallindromic.

Min No of insertion=> length_of_str-lps_of_str
Eg-> abcaa  --> lps => aca                     or                     aaa
        insertions->   a-ab-c-ba-a                                  a-bc-a-cb-a
        Min No of insertions==2
*/


// Method-1=>
class Solution {
    int lps(string &s,int st,int end,vector<vector<int>>&dp){
        if(st>end) return 0;
        else if(st==end) return 1;

        if(dp[st][end]) return dp[st][end];

        if(s[st]==s[end]) return dp[st][end]=2+lps(s,st+1,end-1,dp);
        else return dp[st][end]=max(lps(s,st+1,end,dp),lps(s,st,end-1,dp));
    }
public:
    int minInsertions(string s) {
        int l=s.size();
        
        vector<vector<int>>dp(l,vector<int>(l));
        int lps_len=lps(s,0,l-1,dp);

        cout<<lps_len<<"\n";
        return l-lps_len;
    }
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class Solution {
    int lps(string &s1,string &s2){
        int l=s1.size();

        vector<int>prv(l+1),curr(l+1);

        for(int i=1;i<=l;++i){
            for(int j=1;j<=l;++j){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prv[j-1];
                }else{
                    curr[j]=max(curr[j-1],prv[j]);
                }
            }
            prv=curr;
        }
        return prv[l];
    }
public:
    int minInsertions(string s) {
        int l=s.size();
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());

        int lps_len=lps(s,rev_s);

        cout<<lps_len<<"\n";
        return l-lps_len;
    }
};