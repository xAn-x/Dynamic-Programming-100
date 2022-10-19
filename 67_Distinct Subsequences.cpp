// https://leetcode.com/problems/distinct-subsequences/

// Method-1=>Find all subseq of s and then count how many are same as t->O(2^n*m)

/*
Method-2
Idea-> func(s,idx1,t,idx2)--> return no of ways i can make t till idx2 using first idx1 char of s
    
    int cnt=0;
    if (s[idx1]==t[idx2]){
        ->this mean tell me no of ways I can make t till idx2-1 using first idx1-1 chars of s
        cnt+= func(s,idx1-1,t,idx2-1);
    }
    ->this mean tell me no of ways I can make t till idx2 using first idx1-1 chars of s -> decide to skip this char
    cnt+=func(s,idx-1,t,idx2);
    return cnt;

    BASE-CASE=>
    if(idx2<0) return 1;
    if(idx1<0) return 0;
*/
class Solution {
public:
// Recursion->
    int no_of_ways(string&str,int i1,string&ptr,int i2){
        if(i2<0) return 1;
        if(i1<0) return 0;

        int cnt=0;
        if(str[i1]==ptr[i2]) cnt+=no_of_ways(str,i1-1,ptr,i2-1);
        cnt+=no_of_ways(str,i1-1,ptr,i2);

        return cnt;
    }

    int numDistinct(string s, string t) {
        int l1=s.size(),l2=t.size(); 
        return no_of_ways(s,l1-1,t,l2-1);
    }
 


// Memoization->
    int no_of_ways(string&str,int i1,string&ptr,int i2,vector<vector<int>>&dp){
        if(i2<0) return 1;
        if(i1<0) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];
        
        int cnt=0;
        if(str[i1]==ptr[i2]) cnt+=no_of_ways(str,i1-1,ptr,i2-1,dp);
        cnt+=no_of_ways(str,i1-1,ptr,i2,dp);

        return dp[i1][i2]=cnt;
    }

    int numDistinct(string s, string t) {
        int l1=s.size(),l2=t.size(); 

        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return no_of_ways(s,l1-1,t,l2-1,dp);
    }


// Tabulation->
    int numDistinct(string s, string t) {
        int l1=s.size(),l2=t.size(); 

        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        
        //If t has no char-> only 1 way=>""
        for(int i=0;i<=l1;++i) dp[i][0]=1;

        // i & j are pos and not indexes
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
                dp[i][j]+=dp[i-1][j];
            }
        }

        return dp[l1][l2];
    }


// Tabulation + Space-Optimisation->
        int numDistinct(string s, string t) {
        int l1=s.size(),l2=t.size(); 

        vector<double>prv(l2+1,0),curr(l2+1,0);
        
        //If t has no char-> only 1 way=>""
        prv[0]=curr[0]=1;

        // i & j are pos and not indexes
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(s[i-1]==t[j-1])
                    curr[j]=prv[j-1]+prv[j];
                else
                    curr[j]=prv[j];
            }
            prv=curr;
        }

        return (int)prv[l2];
    }

};

